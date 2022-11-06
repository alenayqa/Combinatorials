using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text;
using System.Globalization;
using System.Text.Json.Serialization;

namespace Archiver
    {
    class HuffmanTree
    {
        private PriorityQueue<Vertex, double> pq;

        private Dictionary<char, string> codes;
        private CultureInfo culture = CultureInfo.CreateSpecificCulture("eu-ES");

        public HuffmanTree()
        {
            pq = new PriorityQueue<Vertex, double>();
            codes = new Dictionary<char, string>();
        }

        private void ReadFreq(string freqFile)
        {
            string line;		
            StreamReader freqList = new StreamReader(freqFile, Encoding.ASCII);

            line=freqList.ReadLine();

            // Новая строка
            char c = '$';
            double freq;

            line=freqList.ReadLine();
            freq = Convert.ToDouble(line.Split(' ')[1], culture);

            pq.Enqueue(new Vertex(c, freq, null, null), freq);

            // Пробел
            c = ' ';
            line=freqList.ReadLine();
            freq = Convert.ToDouble(line, culture);

            pq.Enqueue(new Vertex(c, freq, null, null), freq);

            // Остальные символы
            while ((line = freqList.ReadLine()) != null) 
            {
                string[] s = line.Split(' ');
                c = s[0][0];
                freq = Convert.ToDouble(s[1], culture);
                pq.Enqueue(new Vertex(c, freq, null, null), freq);
            }

            // Конец файла
            c = '^';
            freq = 0.0;

            pq.Enqueue(new Vertex(c, freq, null, null), freq);
        }

        /// <summary>
        /// Построение дерева по частотам
        /// </summary>
        /// <param name="freqFile">Путь до файла с частотами</param>
        public void BuildTree(string freqFile)
        {
            ReadFreq(freqFile);
            while (pq.Count != 1)
            {
                Vertex v1 = pq.Dequeue();
                Vertex v2 = pq.Dequeue();
                pq.Enqueue(new Vertex('#', v1.freq + v2.freq, v1, v2), v1.freq + v2.freq);
            }
            
        }

        private char FindChar(Vertex v, string code)
        {
            if (code.Length == 0)
            {
                return v.symbol;
            }
            if (code[0]=='0')
            {
                return FindChar(v.l, code.Substring(1));
            }
            else
            {
                return FindChar(v.r, code.Substring(1));
            }
        }

        /// <summary>
        /// Разархивирование документа
        /// </summary>
        /// <param name="archiveFile">Путь до архива</param>
        /// <param name="outputFile">Имя выходного файла</param>
        public void Decode(string archiveFile, string outputFile)
        {
            ArchReader ar = new ArchReader(archiveFile);
            StreamWriter fs = new StreamWriter(outputFile);
            byte newBit;
            bool res = ar.ReadBit(out newBit);

            Vertex v = pq.Peek();

            while (res)
            {
                if (newBit == 0)
                {
                    v = v.l;
                }
                else
                {
                    v = v.r;
                }
                char symbol = v.symbol;
                if (symbol!='#')
                {
                    if (symbol == '$')
                    {
                        fs.WriteLine();
                    }
                    else if (symbol == '^')
                    {
                        break;
                    }
                    else
                    {
                        fs.Write(symbol);
                    }
                    v = pq.Peek();
                }
                res = ar.ReadBit(out newBit);

            }
            fs.Close();
            ar.Finish();
        }

        /// <summary>
        /// Архивирование документа
        /// </summary>
        /// <param name="inputFile">Путь до файла с текстом</param>
        /// <param name="archiveFile">Имя архива</param>
        public void Encode(string inputFile, string archiveFile)
        {
            Vertex root = pq.Peek();
            MakeDict(root);
            StreamReader input = new StreamReader(inputFile, Encoding.ASCII);
            string text = input.ReadToEnd();
            ArchWriter aw = new ArchWriter(archiveFile);
            for (int i = 0; i < text.Length; i++)
            {
                if (text[i]==13 && text[i+1]==10)
                {
                    aw.WriteWord(codes['$']);
                    i++;
                }
                else
                {
                    aw.WriteWord(codes[text[i]]);
                }
            }
            aw.WriteWord(codes['^']);
            aw.Finish();
        }
        private void MakeDict(Vertex v, string code = "")
        {
            if (v == null)
            {
                return;
            }

            if (v.symbol != '#')
            {
                codes[v.symbol] = code;
                return;
            }

            MakeDict(v.l, code + "0");
            MakeDict(v.r, code + "1");

        }

    }
}