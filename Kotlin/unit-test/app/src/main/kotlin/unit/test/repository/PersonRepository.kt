package unit.test.repository

import unit.test.model.Person

interface PersonRepository {

    fun selectById(id: String): Person?

    fun insert(person: Person)
}