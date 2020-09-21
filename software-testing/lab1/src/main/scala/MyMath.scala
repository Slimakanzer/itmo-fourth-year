object MyMath {
  final val Precision: Double = 1.11e-8

  def cos(x: Double): Double = {
    @annotation.tailrec
    def loop(n: Int, cur: Double, sum: Double): Double = {
      val dx: Double = -1.0 * x * x / ((2 * n - 1) * (2 * n))

      if (Math.abs(cur) < Precision) sum
      else loop(n + 1, cur * dx, sum + cur)
    }

    loop(1, 1.0, 0.0)
  }

  def arctg(x: Double): Double = {
    if (Math.abs(x) > 1.0d) throw new IllegalArgumentException("argument should be |x| <= 1")

    @annotation.tailrec
    def loop(n: Int, cur: Double, sum: Double): Double = {
      val dx: Double = -1.0 * x * x * (2 * n - 1) / (2 * n + 1)

      if (Math.abs(cur) < Precision) sum
      else loop(n + 1, cur * dx, sum + cur)
    }

    loop(1, x, 0.0)
  }
}
