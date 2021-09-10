// class polos tnapa constructor
class Polos{
    String dataString;
    int dataInteger;
}

//class dengan constructor
class Mahasiswa {
    String nama;
    String NIM;
    String jurusan;

    // constructor dengan Parameter
    Mahasiswa(String inputNama, String inputNIM, String inputjurusan){
        nama = inputNama;
        NIM = inputNIM;
        jurusan = inputjurusan;

        System.out.println(nama);
        System.out.println(NIM);
        System.out.println(jurusan);
    }
}

public class _4_Constructor {
    public static void main(String[] args) {

        Mahasiswa mahasiswa1 = new Mahasiswa("Ucup","G64180065","ILKOM");
        Mahasiswa mahasiswa2 = new Mahasiswa("Otong","G64180099","ILKOM");

    }
}