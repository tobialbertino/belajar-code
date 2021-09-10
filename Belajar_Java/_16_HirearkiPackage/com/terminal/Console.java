package com.terminal;

// all visibility
public class Console {
    public static void log(String message){
        System.out.println(message);
    }
}

// ini hanya akan bisa diakses oleh package terminal
// package yg sama
// class Terminal {
//     public static void log(String message){
//         System.out.println(message);
//     }
// }