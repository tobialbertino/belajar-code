package app

import data.City
import data.Country

fun main() {
    // val location = Location()
    val city = City("Tangerang")
    val country = Country("Indonesia")

    println(city.name)
    println(country.name)
}