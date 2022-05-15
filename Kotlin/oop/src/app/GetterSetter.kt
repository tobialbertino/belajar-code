package app

import data.BigNote
import data.Note

fun main() {
    val note = Note("Learn Kotlin")

    println(note.title)

    note.title = ""
    println(note.title)

    val bigNote = BigNote("Belajar Kotlin")
    println(bigNote.title)
    println(bigNote.bigTitle)

}