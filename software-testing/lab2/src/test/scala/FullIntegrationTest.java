import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class FullIntegrationTest extends IntegrationTest {
    @Before
    public void setup() {
        double precision = 1E-8;
        LightMath math = new LightMath();
        ITrigonometricFunctions tf = new TrigonometricFunctions(precision, math);
        ILogFunctions lf = new LogFunctions(precision, math);
        IComplexFunctions complexFunctions = new ComplexFunctions(tf, lf);

        systemFunctions = new SystemFunctions(complexFunctions);
    }

    /*
     *  Test Positive Values
     */

    /**
     * x = (0.0; 0.55]
     */
    @Test
    public void testFirstPositiveRegionFromZeroX(){
        precisionAssertEquals(
                "Test [x = 0.02]: first positive region from zero X",
                -26465.8,
                systemFunctions.calculate(0.02)
        );
        precisionAssertEquals(
                "Test [x = 0.1]: first positive region from zero X",
                -675.99,
                systemFunctions.calculate(0.1)
        );
        precisionAssertEquals(
                "Test [x = 0.2]: first positive region from zero Xt",
                -60.0068,
                systemFunctions.calculate(0.2)
        );
        precisionAssertEquals(
                "Test [x = 0.3]: first positive region from zero Xt",
                -8.64993,
                systemFunctions.calculate(0.3)
        );
        precisionAssertEquals(
                "Test [x = 0.4]: first positive region from zero Xt",
                -0.999078,
                systemFunctions.calculate(0.4)
        );
        precisionAssertEquals(
                "Test [x = 0.5]: first positive region from zero Xt",
                0.487504,
                systemFunctions.calculate(0.5)
        );
        precisionAssertEquals(
                "Test [x = 0.55]: first positive region from zero Xt",
                0.714449,
                systemFunctions.calculate(0.55)
        );
    }

    /**
     * x = (0.55; 1.0)
     */
    @Test
    public void testSecondPositiveRegionToPuncturePoint() {
        precisionAssertEquals(
                "Test [x = 0.6]: second positive region to first puncture point",
                0.826229,
                systemFunctions.calculate(0.6)
        );
        precisionAssertEquals(
                "Test [x = 0.7]: second positive region to first puncture point",
                0.909484,
                systemFunctions.calculate(0.7)
        );
        precisionAssertEquals(
                "Test [x = 0.8]: second positive region to first puncture point",
                0.928675,
                systemFunctions.calculate(0.8)
        );
        precisionAssertEquals(
                "Test [x = 0.9]: second positive region to first puncture point",
                0.931799,
                systemFunctions.calculate(0.9)
        );
    }

    /**
     * x = 1.0
     */
    @Test
    public void testFirstPositivePuncturePoint() {
        assertTrue(
                "Test [x = 1.0]: first positive puncture point",
                Double.isNaN(systemFunctions.calculate(1d))
        );
    }

    /**
     * x = (1.0; 1.2]
     */
    @Test
    public void testThirdPositiveRegion(){
        precisionAssertEquals(
                "Test [x = 1.05]: third positive region",
                0.931952,
                systemFunctions.calculate(1.05)
        );
        precisionAssertEquals(
                "Test [x = 1.1]: third positive region",
                0.931852,
                systemFunctions.calculate(1.1)
        );
        precisionAssertEquals(
                "Test [x = 1.15]: third positive region",
                0.931464,
                systemFunctions.calculate(1.15)
        );
        precisionAssertEquals(
                "Test [x = 1.2]: third positive region",
                0.930531,
                systemFunctions.calculate(1.2)
        );
    }

    /**
     * x = (1.2; 1.75]
     */
    @Test
    public void testFourthPositiveRegion(){
        precisionAssertEquals(
                "Test [x = 1.3]: fourth positive region",
                0.92594,
                systemFunctions.calculate(1.3)
        );
        precisionAssertEquals(
                "Test [x = 1.5]: fourth positive region",
                0.900074,
                systemFunctions.calculate(1.5)
        );
        precisionAssertEquals(
                "Test [x = 1.75]: fourth positive region",
                0.836129,
                systemFunctions.calculate(1.75)
        );
    }

    /**
     * x = (1.75; e^(2^(2/3) (log(5)/(7 log(10)))^(1/3)))
     */
    @Test
    public void testFifthPositiveRegionToFirstExtreme(){
        precisionAssertEquals(
                "Test [x = 1.8]: fifth positive region",
                0.821522,
                systemFunctions.calculate(1.8)
        );
        precisionAssertEquals(
                "Test [x = 1.9]: fifth positive region",
                0.794358,
                systemFunctions.calculate(1.9)
        );
        precisionAssertEquals(
                "Test [x = 2.0]: fifth positive region",
                0.774356,
                systemFunctions.calculate(2.0)
        );
    }

    /**
     * x = e^(2^(2/3) (log(5)/(7 log(10)))^(1/3))
     */
    @Test
    public void testFirstPositiveExtreme(){
        double extremeX = 2.0884971449233825358269495952366013421428061969691576000370777169;
        double extremeY = 0.76756354102375411049030346684527510737400057387717261292998154511104;

        precisionAssertEquals(
                "Test [x = e^(2^(2/3) (log(5)/(7 log(10)))^(1/3))]: first positive extreme",
                extremeY,
                systemFunctions.calculate(extremeX)
        );
        assertTrue(
                "Test [x = 2.0]: extreme value Y less than left neighborhood value",
                systemFunctions.calculate(2.0) > extremeY
        );
        assertTrue(
                "Test [x = 2.1]: extreme value Y less than right neighborhood value",
                systemFunctions.calculate(2.1) > extremeY
        );
    }

    /**
     * x = ( e^(2^(2/3) (log(5)/(7 log(10)))^(1/3)); +inf)
     */
    @Test
    public void testSixthPositiveRegion() {
        precisionAssertEquals(
                "Test [x = 2.1]: sixth positive region",
                0.767694,
                systemFunctions.calculate(2.1)
        );
        precisionAssertEquals(
                "Test [x = 2.5]: fifth positive region",
                1.02447,
                systemFunctions.calculate(2.5)
        );
        precisionAssertEquals(
                "Test [x = 3.0]: fifth positive region",
                2.63606,
                systemFunctions.calculate(3.0)
        );
        precisionAssertEquals(
                "Test [x = 5.0]: fifth positive region",
                44.3698,
                systemFunctions.calculate(5.0)
        );
        precisionAssertEquals(
                "Test [x = 10.0]: fifth positive region",
                604.538,
                systemFunctions.calculate(10.0)
        );
        precisionAssertEquals(
                "Test [x = 20.0]: fifth positive region",
                3935.8,
                systemFunctions.calculate(20.0)
        );
        precisionAssertEquals(
                "Test [x = 100.0]: fifth positive region",
                81368.217,
                systemFunctions.calculate(100.0)
        );
    }

    /*
     *  Test Negative/Zero Values
     */

    /**
     * x = 0
     */
    @Test
    public void testZeroPuncturePoint(){
        assertTrue(
                "Test [x = 0.0]: zero value puncture point",
                Double.isNaN(systemFunctions.calculate(0))
        );
    }

    /**
     * x = (-1.2; 0.0)
     */
    @Test
    public void testFirstNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -0.4]: first negative region",
                50.2412,
                systemFunctions.calculate(-0.4)
        );
        precisionAssertEquals(
                "Test [x = 0.7]: first negative region",
                10.964,
                systemFunctions.calculate(-0.7)
        );
        precisionAssertEquals(
                "Test [x = -1.15]: first negative region",
                3.65397,
                systemFunctions.calculate(-1.15)
        );
    }

    /**
     * x = -1.2
     */
    @Test
    public void testFirstNegativeExtremePoint() {
        double extremeY = 3.60465;
        precisionAssertEquals(
                "Test [x = -1.2]: first negative extreme point",
                extremeY,
                systemFunctions.calculate(-1.2)
        );
        assertTrue(
                "Test [x = -1.2]: extreme value Y less than left neighborhood",
                systemFunctions.calculate(-1.25) > extremeY
        );
        assertTrue(
                "Test [x = -1.2]: extreme value Y high less right neighborhood",
                systemFunctions.calculate(-1.15) > extremeY
        );
    }

    /**
     * x = (-pi/2; -1.2)
     */
    @Test
    public void testSecondNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -1.3]: second negative region",
                3.97437,
                systemFunctions.calculate(-1.3)
        );
        precisionAssertEquals(
                "Test [x = -1.4]: second negative region",
                5.61428,
                systemFunctions.calculate(-1.4)
        );
        precisionAssertEquals(
                "Test [x = -1.5]: second negative region",
                13.4263,
                systemFunctions.calculate(-1.5)
        );
    }

    /**
     * x = -pi/2
     */
    @Test
    public void testFirstNegativePuncturePoint(){
        var result = systemFunctions.calculate(-Math.PI / 2);
        assertTrue(
                "Test [x = -pi/2]: puncture point",
                Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
        );
    }

    /**
     * x = (-1.95; -pi/2)
     */
    @Test
    public void testThirdNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -1.7]: third negative region",
                -9.26823,
                systemFunctions.calculate(-1.7)
        );
        precisionAssertEquals(
                "Test [x = -1.8]: third negative region",
                -6.30266,
                systemFunctions.calculate(-1.8)
        );
        precisionAssertEquals(
                "Test [x = -1.9]: third negative region",
                -5.40983,
                systemFunctions.calculate(-1.9)
        );
    }

    /**
     * x = -1.95
     */
    @Test
    public void testSecondNegativeExtremePoint() {
        double extremeY = -5.23951;
        precisionAssertEquals(
                "Test [x = -1.95]: second negative extreme point",
                extremeY,
                systemFunctions.calculate(-1.95)
        );
        assertTrue(
                "Test [x = -1.9]: extreme value Y greater than left neighborhood",
                systemFunctions.calculate(-1.9) < extremeY
        );
        assertTrue(
                "Test [x = -2.1]: extreme value Y greater right neighborhood",
                systemFunctions.calculate(-2.1) < extremeY
        );
    }

    /**
     * x = (-pi; -1.95)
     */
    @Test
    public void testFourthNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -2.2]: fourth negative region",
                -5.61752,
                systemFunctions.calculate(-2.2)
        );
        precisionAssertEquals(
                "Test [x = -2.5]: fourth negative region",
                -8.44473,
                systemFunctions.calculate(-2.5)
        );
        precisionAssertEquals(
                "Test [x = -2.8]: fourth negative region",
                -21.5672,
                systemFunctions.calculate(-2.8)
        );
        precisionAssertEquals(
                "Test [x = -3.1]: fourth negative region",
                -1171.27,
                systemFunctions.calculate(-3.1)
        );
    }

    /**
     * x = -pi
     */
    @Test
    public void testSecondNegativePuncturePoint() {
        double result = systemFunctions.calculate(-Math.PI);
        assertTrue(
                "Test [x = -pi]: puncture point",
                Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
        );
    }

    /**
     * x = (-4.25; -pi)
     */
    @Test
    public void testFifthNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -3.2]: fifth negative region",
                -580.903,
                systemFunctions.calculate(-3.2)
        );
        precisionAssertEquals(
                "Test [x = -3.5]: fifth negative region",
                -17.4998,
                systemFunctions.calculate(-3.5)
        );
        precisionAssertEquals(
                "Test [x = -3.8]: fifth negative region",
                -7.27089,
                systemFunctions.calculate(-3.8)
        );
        precisionAssertEquals(
                "Test [x = -4.2]: fifth negative region",
                -5.05901,
                systemFunctions.calculate(-4.2)
        );
    }

    /**
     * x = -4.25
     */
    @Test
    public void testThirdNegativeExtremePoint() {
        double extremeY = -5.04151;
        precisionAssertEquals(
                "Test [x = -4.25]: third negative extreme point",
                extremeY,
                systemFunctions.calculate(-4.25)
        );
        assertTrue(
                "Test [x = -4.2]: extreme value Y greater than left neighborhood",
                systemFunctions.calculate(-4.2) < extremeY
        );
        assertTrue(
                "Test [x = -4.3]: extreme value Y greater right neighborhood",
                systemFunctions.calculate(-4.3) < extremeY
        );
    }

    /**
     * x = (-3pi/2; -4.25)
     */
    @Test
    public void testSixthNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -4.3]: sixth negative region",
                -5.08678,
                systemFunctions.calculate(-4.3)
        );
        precisionAssertEquals(
                "Test [x = -4.4]: sixth negative region",
                -5.45166,
                systemFunctions.calculate(-4.4)
        );
        precisionAssertEquals(
                "Test [x = -4.5]: sixth negative region",
                -6.5621,
                systemFunctions.calculate(-4.5)
        );
        precisionAssertEquals(
                "Test [x = -4.6]: sixth negative region",
                -10.3553,
                systemFunctions.calculate(-4.6)
        );
    }

    /**
     * x = -3pi/2
     */
    @Test
    public void testThirdNegativePuncturePoint(){
        double result = systemFunctions.calculate(-3 * Math.PI / 2);
        assertTrue(
                "Test [x = -3pi/2]: puncture point",
                Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
        );
    }

    /**
     * x = (-5.15; -3pi/2)
     */
    @Test
    public void testSeventhNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -4.8]: seventh negative region",
                10.7877,
                systemFunctions.calculate(-4.8)
        );
        precisionAssertEquals(
                "Test [x = -4.9]: seventh negative region",
                5.15571,
                systemFunctions.calculate(-4.9)
        );
        precisionAssertEquals(
                "Test [x = -5.0]: seventh negative region",
                3.78871,
                systemFunctions.calculate(-5.0)
        );
        precisionAssertEquals(
                "Test [x = -5.1]: seventh negative region",
                3.41948,
                systemFunctions.calculate(-5.1)
        );
    }

    /**
     * x = -5.15
     */
    @Test
    public void testFourthNegativeExtremePoint() {
        double extremeY = 3.40621;
        precisionAssertEquals(
                "Test [x = -5.15]: fourth negative extreme point",
                extremeY,
                systemFunctions.calculate(-5.15)
        );
        assertTrue(
                "Test [x = -5.1]: extreme value Y less than left neighborhood",
                systemFunctions.calculate(-5.1) > extremeY
        );
        assertTrue(
                "Test [x = -5.2]: extreme value Y less right neighborhood",
                systemFunctions.calculate(-5.2) > extremeY
        );
    }

    /**
     * x = (-5.7; -5.15)
     */
    @Test
    public void testEightNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -5.3]: eight negative region",
                3.74355,
                systemFunctions.calculate(-5.3)
        );
        precisionAssertEquals(
                "Test [x = -5.4]: eight negative region",
                4.16767,
                systemFunctions.calculate(-5.4)
        );
        precisionAssertEquals(
                "Test [x = -5.5]: eight negative region",
                4.66807,
                systemFunctions.calculate(-5.5)
        );
        precisionAssertEquals(
                "Test [x = -5.6]: eight negative region",
                5.12033,
                systemFunctions.calculate(-5.6)
        );
    }

    /**
     * x = -5.65
     */
    @Test
    public void tesFifthNegativeExtremePoint() {
        double extremeY = 5.24277;
        precisionAssertEquals(
                "Test [x = -5.65]: fourth negative extreme point",
                extremeY,
                systemFunctions.calculate(-5.65)
        );
        assertTrue(
                "Test [x = -5.6]: extreme value Y greater than left neighborhood",
                systemFunctions.calculate(-5.6) < extremeY
        );
        assertTrue(
                "Test [x = -5.7]: extreme value Y greater right neighborhood",
                systemFunctions.calculate(-5.7) < extremeY
        );
    }

    /**
     * x = (-2pi; -5.65)
     */
    @Test
    public void testNineNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -5.8]: nine negative region",
                3.89952,
                systemFunctions.calculate(-5.8)
        );
        precisionAssertEquals(
                "Test [x = -6.0]: nine negative region",
                -29.835,
                systemFunctions.calculate(-6.0)
        );
        precisionAssertEquals(
                "Test [x = -6.2]: nine negative region",
                -2866.63,
                systemFunctions.calculate(-6.2)
        );
    }

    /**
     * x = -pi/2 * i
     */
    @Test
    public void testPuncturePointPeriodically(){
        for (int i = 1; i < 12; i++) {
            double x = -Math.PI / 2 * i;
            double result = systemFunctions.calculate(x);
            assertTrue(
                    "Test [x = -" + i + "*pi / 2]: puncture point periodically",
                    Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
            );
        }
    }

    /**
     * x = -1.2 - 2pi*i
     */
    @Test
    public void testFirstNegativeExtremePointPeriodically() {
        double extremeY = 3.60465;
        for (int i = 1; i < 5; i++) {
            double x = -1.2 - 2*Math.PI*i;
            precisionAssertEquals(
                    "Test [x = "+i+"]: first negative extreme point periodically",
                    extremeY,
                    systemFunctions.calculate(x)
            );
        }
    }

    /**
     * x = -1.95 - 2pi*i
     */
    @Test
    public void testSecondNegativeExtremePointPeriodically() {
        double extremeY = -5.23951;
        for (int i = 1; i < 5; i++) {
            double x = -1.95 - 2*Math.PI*i;

            precisionAssertEquals(
                    "Test [x = " + i + "]: second negative extreme point periodically",
                    extremeY,
                    systemFunctions.calculate(x)
            );
        }
    }

    /**
     * x = -4.25 - 2pi*i
     */
    @Test
    public void testThirdNegativeExtremePointPeriodically() {
        double extremeY = -5.04151;
        for (int i = 1; i < 5; i++) {
            double x = -4.25 - 2*Math.PI*i;

            precisionAssertEquals(
                    "Test [x = " + i + "]: third negative extreme point periodically",
                    extremeY,
                    systemFunctions.calculate(x)
            );
        }
    }

    /**
     * x = -5.15 - 2pi*i
     */
    @Test
    public void testFourthNegativeExtremePointPeriodically() {
        double extremeY = 3.40621;
        for (int i = 1; i < 5; i++) {
            double x = -5.15 - 2*Math.PI*i;

            precisionAssertEquals(
                    "Test [x = " + i + "]: fourth negative extreme point periodically",
                    extremeY,
                    systemFunctions.calculate(x)
            );
        }
    }

    /**
     * x = -5.65 - 2pi*i
     */
    @Test
    public void testFifthNegativeExtremePointPeriodically() {
        double extremeY = 5.24277;
        for (int i = 1; i < 5; i++) {
            double x = -5.65 - 2*Math.PI*i;

            precisionAssertEquals(
                    "Test [x = " + i + "]: fifth negative extreme point periodically",
                    extremeY,
                    systemFunctions.calculate(x)
            );
        }
    }
}
