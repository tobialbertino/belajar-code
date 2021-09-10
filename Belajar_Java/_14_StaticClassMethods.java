
import java.util.ArrayList;

class Player{

    private static int numberOfPlayer;
    private static ArrayList<String> nameList = new ArrayList<String>();
    private String name;

    Player(String name){
        this.name = name;
        Player.numberOfPlayer++;
        Player.nameList.add(this.name);
    }

    void show(){
        System.out.println("player name = " + this.name);
    }

    // static method
    static void showNumberOfPlayer(){
        System.out.println("Number of player = "  + Player.numberOfPlayer);
    }
    static ArrayList<String> getName(){
        return Player.nameList;
    }
}

class _14_StaticClassMethods{
    public static void main(String[] args) {
        Player player1 = new Player("Saitama");
        Player player2 = new Player("All Mighty");
        Player player3 = new Player("Midnight");
        Player player4 = new Player("Mt Lady");

        Player.showNumberOfPlayer();

        System.out.println("Names = "+ Player.getName());
        // System.out.println("Names = "+ player1.getName());
    }
}