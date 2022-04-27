fun main() {
  var firstName: String = "Tobi"
  var lastName: String = "Albertino"
  var fullName: String = "$firstName $lastName"
  var desc: String = "$fullName length = ${fullName.length}"

  var address: String = """
    |Jalan belum jadi No.123, 
    |Kab Pelangi, 
    |Kota Empire, 
    |Indonesia.
    """.trimMargin()

  println(firstName)
  println(lastName)
  println(address)
  println(fullName)
  println(desc)
}