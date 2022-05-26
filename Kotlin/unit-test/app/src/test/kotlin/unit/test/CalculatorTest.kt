package unit.test

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.*
import org.junit.jupiter.api.Assumptions.*
import org.opentest4j.TestAbortedException
import unit.test.generator.SimpleDisplayNameGenerator

// @DisplayName("Test for Calculator Class")
@DisplayNameGeneration(SimpleDisplayNameGenerator::class)
class CalculatorTest {

    companion object {
        @BeforeAll
        @JvmStatic
        fun beforeAll() {
            println("Sebelum semua unit test")
        }

        @AfterAll
        @JvmStatic
        fun afterAll() {
            println("Setelah semua unit test")
        }
    }
    val calculator = Calculator()

    @BeforeEach
    fun beforeEach() {
        println("Sebelum unit test")
    }

    @AfterEach
    fun afterEach() {
        println("Setelah unit test")

    }

    @Test
    // @DisplayName("Test for Calculator.add(10, 10)")
    fun testAddSuccess() {
        println("unit test testAddSuccess")
        val result = calculator.add(10, 10)
        assertEquals(20, result, "Hasil yang benar 20")
    }

    @Test
    // @DisplayName("Test for Calculator.add(15, 15)")
    fun testAddSuccess2() {
        val result = calculator.add(15, 15)
        assertEquals(30, result, "Hasil yang benar 30")
    }

    @Test
    fun testDivideSuccess() {
        val result = calculator.divide(15, 5)
        assertEquals(3, result, "Hasil yang benar 3")
    }

    @Test
    fun testDivideFailed() {
        assertThrows<IllegalArgumentException> {
            calculator.divide(10, 0)
        }
    }

    @Disabled("Proses")
    @Test
    fun testComingSoon() {
        // Belum selesai
    }

    @Test
    fun testAborted() {
        val profile = System.getenv()["PROFILE"]
        if (profile != "DEV") {
            throw TestAbortedException()
        }
        println("Test Not Aborted because dev profile")
    }

    @Test
    fun testAssumption() {
        assumeTrue("DEV" == System.getenv()["PROFILE"])

        println("Test Not Aborted because dev profile")
    }
}