package app

fun main() {
    val mutableList: MutableList<String> = mutableListOf()
    mutableList.add("M")
    mutableList.add("Khoiru")
    mutableList.add("Tobi")

    // mutableList[0] = "Budi"
    // mutableList.remove("M")

    for (value in mutableList) {
         println(value)
    }
}