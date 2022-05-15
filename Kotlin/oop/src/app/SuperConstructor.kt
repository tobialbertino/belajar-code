package app

import data.ExecutiveCustomer
import data.PremiumCustomer

fun main() {
    val premiumCustomer = PremiumCustomer("Tobi")
    println(premiumCustomer.name)

    val executiveCustomer = ExecutiveCustomer("Budi", 1000000)
    println(executiveCustomer.name)
    println(executiveCustomer.balance)
}