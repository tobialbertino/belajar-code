
class Player{
    String name; // default, dia akan bisa dibaca dan ditulis
    public int exp; // public, dia akan bisa dibaca dan ditulis dari luar class
    private int health; // private, hanya akan bisa dibaca dan ditulis didalam class saja

    Player(String name, int exp, int health) {
        this.name = name;
        this.exp = exp;
        this.health = health;
    }

    // default modifier acces
    void display(){
        tambahExp(); // contoh mengakses private methods
        System.out.println("\nName\t: " + this.name);
        System.out.println("exp\t: " + this.exp);
        System.out.println("health\t: " + this.health); // membaca, didalam class
    }

    // public
    public void ubahName(String nameBaru){
        this.name = nameBaru;
    }

    // private
    private void tambahExp(){
        this.exp += 100;
    }
}

public class _9_PublicPrivate{
    public static void main(String[] args) {
        Player player1 = new Player("Marni", 0, 100);
        
        // default
        System.out.println(player1.name); // membaca data
        player1.name = "Surti"; // menulis data
        System.out.println(player1.name); // membaca data
        
        // public
        System.out.println(player1.exp); // membaca data
        player1.exp = 100; // menulis data
        System.out.println(player1.exp); // membaca data

        // private (tidak bisa diakses)
        // System.out.println(player1.health); // membaca data
        // player1.health = 100; // menulis data
        // System.out.println(player1.health); // membaca data

        // method

        // default
        player1.display();

        // public
        player1.ubahName("Tejo");
        player1.display();

        // private (tidak bisa diakses dari luar)
        // player1.tambahExp();
    }
}