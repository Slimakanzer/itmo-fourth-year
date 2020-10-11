import scala.annotation.tailrec

class LightMath {
  final val Precision: Double = 1.11e-8
  final val PI = 3.14159265358979323846
  final val E = 2.7182818284590452354

  def sin(x: Double): Double = sin(x, Precision)

  def sin(x: Double, precision: Double): Double = {
    @tailrec
    def loop(sum: Double, cur: Double, n: Int): Double = {
      if (Math.abs(cur) < precision) return sum

      val dx = -x*x / (2*n*(2*n+1))
      val next = cur * dx
      loop(sum+next, next, n+1)
    }

    loop(x, x, 1)
  }

  def ln(x: Double): Double = ln(x, Precision)

  def ln(x: Double, precision: Double): Double = {
    if (x <= 0) throw new IllegalArgumentException("x should be: x > 0")

    @tailrec
    def loop(sum: Double, cur: Double, n: Int): Double = {
      if (Math.abs(cur) < precision) return sum

      val next = cur * ((x - 1) * (x - 1)) / ((x + 1) * (x + 1))
      val ds = next / (2 * n + 1)
      loop(sum + ds, next, n + 1)
    }

    val first = (x - 1) / (x + 1)
    2 * loop(first, first, 1)
  }

  def cos(x: Double): Double = cos(x, Precision)

  def  cos(x: Double, precision: Double): Double = {
    val sinRes = sin(x, precision)
    val trigEquality = Math.sqrt(1 - sinRes * sinRes)

    val mod = x % (2 * PI)
    if (mod >= 0) {
      if (mod > PI / 2 && mod < 3 * PI / 2) -trigEquality
      else trigEquality
    }
    else {
      if (mod < -PI / 2 && mod > -3 * PI / 2) -trigEquality
      else trigEquality
    }
  }
}
