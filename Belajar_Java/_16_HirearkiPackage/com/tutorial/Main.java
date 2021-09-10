package com.tutorial;
// import class
import com.terminal.Console;
import com.terminal.Terminal;

// import static method dari console
import static com.terminal.Console.log;


class Main{
    public static void main(String[] args) {
        
        Player player1 = new Player("Otong");
        Player player2 = new Player("Ucup");
        Player player3 = new Player("Saitama");
        player1.show();
        player2.show();
        player3.show();

        Console.log("Hello");
        Console.log("Hello");
        Console.log(player1.getName());
        Terminal.log(player1.getName());

        log("Menampilkan data dengan log saja");
        log(player1.getName());
    }
}