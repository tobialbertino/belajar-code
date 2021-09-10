
class Player{
    private String name;
    private static int jumlahPlayer;

    // Overloading constructor
    // opsi 1
    Player(String name){ 
        Player.jumlahPlayer++;  
        this.name = name; 
    }
    //opsi 2
    Player(){ 
        Player.jumlahPlayer++;
        this.name = "Player " + Player.jumlahPlayer; 
    }

    void show(){ System.out.println("Name : "+ this.name); }
}

class Matematika{

    public static int tambah(int x, int y){
        return x + y;
    }
    public static double tambah(double x, double y){
        return x + y;
    }
    public static double tambah(int x, double y){
        return (double)x + y;
    }
}

public class _17_Overloading{
    public static void main(String[] args) {
        Player player1 = new Player("Saitama");
        Player player2 = new Player();
        Player player3 = new Player();
        Player player4 = new Player("Asta");

        player1.show();
        player2.show();
        player3.show();
        player4.show();

        // Overloading methods
        int a = Matematika.tambah(11, 9);
        System.out.println(a);
        double b = Matematika.tambah(1.07, 0.98);
        System.out.println(b);
        double c = Matematika.tambah(1.02, 0.98);
        System.out.println(c);
    }
}