package unit.test

import org.junit.jupiter.api.MethodOrderer
import org.junit.jupiter.api.TestMethodOrder
import org.junit.jupiter.api.*

@TestInstance(value = TestInstance.Lifecycle.PER_CLASS)
@TestMethodOrder(value = MethodOrderer.OrderAnnotation::class)
class OrderTest {
    @BeforeAll
    fun beforeAll() {}

    @AfterAll
    fun afteraAll() {}

    var counter: Int = 0
    @Test
    @Order(3)
    fun tes1() {
        counter++
        println(counter)
    }

    @Test
    @Order(2)
    fun tes2() {
        counter++
        println(counter)
    }

    @Test
    @Order(1)
    fun tes3() {
        counter++
        println(counter)
    }
}