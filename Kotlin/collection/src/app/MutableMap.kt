package app

fun main() {
    val mutableMap: MutableMap<String, String> = mutableMapOf()
    mutableMap.put("a", "Tobi")
    mutableMap["b"] = "Albertino"
    mutableMap["c"] = "Test"

    println(mutableMap.get("a"))
    println(mutableMap["b"])
    println(mutableMap["c"])
    println(mutableMap.getOrDefault("d", "Tidak ada"))
    println(mutableMap.get("d"))

    mutableMap.remove("c")

    for ((key, value) in mutableMap) {
        println("$key to $value")
    }
}