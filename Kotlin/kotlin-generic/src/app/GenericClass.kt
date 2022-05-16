package app

import data.MyData

fun main() {
    val myDataString: MyData<String, Int> = MyData("Tobi", 21)
    myDataString.printData()

    val myDataInt: MyData<Int, String> = MyData(21, "Tobi")
    myDataInt.printData()


}