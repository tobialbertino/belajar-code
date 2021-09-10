class Buku{
    String judul;
    String penulis;

    Buku (String judul, String penulis){
        this.judul = judul;
        this.penulis = penulis;
    }

    void display() {
        System.out.println("\nJudul\t: " + this.judul);
        System.out.println("Penulis\t: " + this.penulis);
    }
}

public class _8_Reference{
    public static void main(String[] args) {
        Buku buku1 = new Buku("Kiling Commandantore", "Haruki Murakami");
        buku1.display();

        // Menampilkan addres
        String addresBuku1 = Integer.toHexString(System.identityHashCode(buku1));
        System.out.println(addresBuku1);
        
        // assigment object
        Buku buku2 = buku1;
        buku2.display();
        String addresBuku2 = Integer.toHexString(System.identityHashCode(buku2));
        System.out.println(addresBuku2);

        // karena buku1 dan buku2 berada pada addres yg sama
        buku1.judul = "Membunuh Komandatur";
        buku1.display();
        buku2.display();
        
        // lita akan memasukkan object kedalam method
        fungsi(buku2);
        buku1.display();
        buku2.display();
    }
    
    public static void fungsi(Buku dataBuku){
        String addresDataBuku = Integer.toHexString(System.identityHashCode(dataBuku));
        System.out.println("addres dalam fungsi " + addresDataBuku);
        dataBuku.penulis = "Haruki Mahalkami";
    }
}