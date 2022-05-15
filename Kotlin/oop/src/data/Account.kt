package data

import kotlin.properties.Delegates
import kotlin.properties.ObservableProperty

class Account(description: String = "") {
    val name: String by lazy {
        println("name is called")
        "Tobi"
    }

    var description: String by Delegates.observable(description) {
        property, oldValue, newValue ->
        println("${property.name} is changed from $oldValue to $newValue")
    }
}