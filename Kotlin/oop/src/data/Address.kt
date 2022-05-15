package data

class Address {

    constructor(paramStreet: String, paramCity: String){
        street = paramStreet
        city = paramCity
    }

    constructor(paramStreet: String, paramCity: String, paramCountry: String) : this(paramStreet, paramCity){
        country = paramCountry
    }

    var street: String = ""
    var city: String = ""
    var country: String = "Indonesia"
}