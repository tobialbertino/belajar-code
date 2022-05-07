fun fullName(
    firstName: String,
    middleName: String,
    lastName: String
) {
    println("Hello $firstName $middleName $lastName")
}

fun main() {
    fullName("Eko", "Kurniawan", "Khannedy")
    fullName(
        lastName = "Tobi",
        firstName = "M",
        middleName = "Khoiru"
    )
}