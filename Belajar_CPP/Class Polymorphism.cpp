class Ruang2D
{
    protected:
        int width, height;
    public:
        Ruang2D(int a=0, int b=0) { width=a; height=b; } 
        virtual int area() {
            cout << "Luas Ruang2D: ";
            return 0;
        } 
};

class Segiempat: public Ruang2D
{
    public:
        Segiempat(int a=0, int b=0) { width = a; height = b; } 
        int area () {
            cout << "Luas Segiempat: ";
            return (width * height);
        } 
};

class Segitiga: public Ruang2D
{
    public:
        Segitiga(int a=0, int b=0) { width = a; height = b; } 
        int area () {
            cout << "Luas Segitiga: ";
            return (width*height/2);
        }
};

int main() {
   Ruang2D *r;               // buat objek Ruang2D
   Segiempat s(10,7);        // buat objek segiempat s
   Segitiga  t(10,5);        // buat objek segitiga t

   r = &s;                   // objek r menunjuk objek segiempat
   cout << r->area() << endl;

   r = &t;                   // objek r menunjuk objek segitiga
   cout << r->area() << endl;
   
   return 0;
}