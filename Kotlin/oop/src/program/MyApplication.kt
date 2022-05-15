package program

import annotations.Fancy

@Fancy(author = "Tobi")
class MyApplication(val name: String, val version: Int) {
    fun info(): String = "Application: $name-$version"
}