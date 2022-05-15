package data

class Laptop(val name: String)

open class HandPhone(val name: String)

class Smartphone(name: String, val os: String) : HandPhone(name)