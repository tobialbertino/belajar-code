package data

class MyData<T, U>(val firstData: T, val secondData: U) {
    fun getData(): T = firstData

    fun getSecond(): U = secondData

    fun printData(): Unit = println("Data is $firstData and $secondData")
}