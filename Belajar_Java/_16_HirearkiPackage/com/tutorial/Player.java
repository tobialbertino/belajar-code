package com.tutorial;

import com.terminal.Console;

// visibility deafult
class Player{
    private String name;

    Player(String name){
        this.name = name;
    }

    void setName(String name){
        this.name = name;
    }
    String getName(){
        return this.name;
    }
    void show(){
        // System.out.println("Player name = " + this.name);
        Console.log("Menggunakan Console");
        Console.log("Player name = " + this.name);
    }
}