class Mahasiswa{
    //data member
    String nama;
    String NIM;

    //constructor
    Mahasiswa(String nama, String NIM) {
        this.nama = nama;
        this.NIM = NIM;
    }

    // method tanpa return dan tanpa parameter
    void show() {
        System.out.println("Nama : " + this.nama);
        System.out.println("NIM  : " + this.NIM);
    }
    // method tanpa return, dengan parameter
    void setNama(String nama) {
        this.nama = nama;
    }
    // method dengan return, tanpa parameter
    String getNama() {
        return this.nama;
    }
    String getNIM() {
        return this.NIM;
    }
    // method dengan return dan parameter
    String sayHI(String message){
        return message + " juga, nama saya adalah " + this.nama;
    }
}

public class _5_Methods {
    public static void main(String[] args) {
        Mahasiswa mahasiswa1 = new Mahasiswa("Ucup", "G64180065");
        System.out.println(mahasiswa1.nama);
        // method
        mahasiswa1.show();
        mahasiswa1.setNama("Tutung");
        mahasiswa1.show();

        System.out.println(mahasiswa1.getNama());
        System.out.println(mahasiswa1.getNIM());

        
        System.out.println(mahasiswa1.sayHI("Hello"));
    }

}