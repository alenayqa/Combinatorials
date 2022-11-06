using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text;
using System.Text.Json.Serialization;


namespace Archiver
{
    class ArchiverProgram 
    {         
        static void Main(string[] args)
        {
            var json = File.ReadAllText("config.json");
            var values = JsonSerializer.Deserialize<Dictionary<string, string>>(json);

            string freqFile = "";
            string inputFile = "";
            string archiveFile = "";
            string outputFile = "";
            if (values!=null)
            {
                inputFile = values["input-path"];
                freqFile = values["freq-path"];
                archiveFile = values["archive-path"];
                outputFile = values["output-path"];
            }
            
            HuffmanTree ht = new HuffmanTree();
            ht.BuildTree(freqFile);
            ht.Encode(inputFile, archiveFile);
            ht.Decode(archiveFile, outputFile);

        }
    }
}