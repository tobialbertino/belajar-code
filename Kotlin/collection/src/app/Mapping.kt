package app

fun main() {
    val list: List<String> = listOf("Eko", "Kurniawan", "Khannedy")

//    val temp = mutableListOf<String>()
//    for(value in list){
//        temp.add(value.uppercase())
//    }

    // val list2 = list.map { value -> value.uppercase() }
    val list2 = list.map { it.uppercase() }
    println(list2)

    val set1 = setOf("Eko", "Kurniawan", "Khannedy")
    val set2 = set1.map { it.lowercase() }
    println(set2)

    val names = listOf("Eko", "Budi", "Joko", "Dani", "Andi", "Hendri")
    val namesGanjil = names.mapIndexedNotNull { index, name ->
        if (index % 2 == 0) null
        else name
    }
    println(namesGanjil)

    val numbers = (1..100).toList()
    val ganjil = numbers.mapNotNull {
        if(it % 2 == 0) null
        else it
    }
    println(ganjil)
}