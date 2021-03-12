import kotlin.random.Random

class DndCharacter {

    val strength: Int = ability()
    val dexterity: Int = ability()
    val constitution: Int = ability()
    val intelligence: Int = ability()
    val wisdom: Int = ability()
    val charisma: Int = ability()
    val hitpoints: Int = 10 + modifier(constitution)

    companion object {

        fun ability(): Int {
            val randoms = List(4) { Random.nextInt(1, 6) }
            return randoms.sorted().reversed().take(3).sum()
        }

        fun modifier(score: Int): Int {
            var mod = score - 10
            if (mod % 2 == 0 || mod >= 0) {
                mod /= 2
            } else {
                mod = (mod / 2) - 1
            }

            return mod
        }
    }
}
