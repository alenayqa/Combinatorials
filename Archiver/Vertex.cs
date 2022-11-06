namespace Archiver
{
    class Vertex
    {
        public char symbol;
        public double freq;
        public Vertex l;
        public Vertex r;

        public Vertex(char symbol, double freq, Vertex l = null, Vertex r = null)
        {
            this.symbol = symbol;
            this.freq = freq;
            this.l = l;
            this.r = r;
        }
    }
}
