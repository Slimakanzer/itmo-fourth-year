import org.junit.Before;
import org.junit.Test;

import static org.mockito.Mockito.*;
import static org.junit.Assert.*;

public class BasicFunctionsIntegrationTest extends IntegrationTest {
    @Before
    public void mockBasicFunctions() {
        double precision = 1E-8;
        LightMath math = mock(LightMath.class);

        when(math.ln(0.02, precision)).thenReturn(-3.912023005428146);
        when(math.ln(0.1, precision)).thenReturn(-2.3025850929940455);
        when(math.ln(0.2, precision)).thenReturn(-1.6094379124341003);
        when(math.ln(0.3, precision)).thenReturn(-1.2039728043259361);
        when(math.ln(0.4, precision)).thenReturn(-0.916290731874155);
        when(math.ln(0.5, precision)).thenReturn(-0.6931471805599453);
        when(math.ln(0.55, precision)).thenReturn(-0.5978370007556204);

        when(math.ln(0.6, precision)).thenReturn(-0.5108256237659907);
        when(math.ln(0.7, precision)).thenReturn(-0.35667494393873245);
        when(math.ln(0.8, precision)).thenReturn(-0.2231435513142097);
        when(math.ln(0.9, precision)).thenReturn(-0.10536051565782628);

        when(math.ln(1.0, precision)).thenReturn(0.0);

        when(math.ln(1.05, precision)).thenReturn(0.04879016416943204);
        when(math.ln(1.1, precision)).thenReturn(0.09531017980432493);
        when(math.ln(1.15, precision)).thenReturn(0.13976194237515863);
        when(math.ln(1.2, precision)).thenReturn(0.1823215567939546);

        when(math.ln(1.3, precision)).thenReturn(0.26236426446749106);
        when(math.ln(1.5, precision)).thenReturn(0.4054651081081644);
        when(math.ln(1.75, precision)).thenReturn(0.5596157879354227);

        when(math.ln(1.8, precision)).thenReturn(0.5877866649021191);
        when(math.ln(1.9, precision)).thenReturn(0.6418538861723947);
        when(math.ln(2.0, precision)).thenReturn(0.6931471805599453);

        when(math.ln(2.0884971449233825358269495952366013421428061969691576000370777169, precision)).thenReturn(0.7364447379076575);

        when(math.ln(2.1, precision)).thenReturn(0.7419373447293773);
        when(math.ln(2.5, precision)).thenReturn(0.9162907318741551);
        when(math.ln(3.0, precision)).thenReturn(1.0986122886681098);
        when(math.ln(5.0, precision)).thenReturn(1.6094379124341003);
        when(math.ln(10.0, precision)).thenReturn(2.302585092994046);
        when(math.ln(20.0, precision)).thenReturn(2.995732273553991);
        when(math.ln(100.0, precision)).thenReturn(4.605170185988092);

        when(math.sin(-0.4, precision)).thenReturn(-0.3894183423086505);
        when(math.cos(-0.4, precision)).thenReturn(0.9210609940028851);
        when(math.sin(-0.7, precision)).thenReturn(-0.644217687237691);
        when(math.cos(-0.7, precision)).thenReturn(0.7648421872844885);
        when(math.sin(-1.15, precision)).thenReturn(-0.912763940260521);
        when(math.cos(-1.15, precision)).thenReturn(0.4084874408841574);

        when(math.sin(-1.2, precision)).thenReturn(-0.9320390859672263);
        when(math.cos(-1.2, precision)).thenReturn(0.3623577544766736);
        when(math.sin(-1.25, precision)).thenReturn(-0.9489846193555862);
        when(math.cos(-1.25, precision)).thenReturn(0.3153223623952687);

        when(math.sin(-1.3, precision)).thenReturn(-0.963558185417193);
        when(math.cos(-1.3, precision)).thenReturn(0.26749882862458735);
        when(math.sin(-1.4, precision)).thenReturn(-0.9854497299884601);
        when(math.cos(-1.4, precision)).thenReturn(0.16996714290024104);
        when(math.sin(-1.5, precision)).thenReturn(-0.9974949866040544);
        when(math.cos(-1.5, precision)).thenReturn(0.0707372016677029);

        when(math.sin(-1.7, precision)).thenReturn(-0.9916648104524686);
        when(math.cos(-1.7, precision)).thenReturn(-0.12884449429552464);
        when(math.sin(-1.8, precision)).thenReturn(-0.9738476308781951);
        when(math.cos(-1.8, precision)).thenReturn(-0.2272020946930871);
        when(math.sin(-1.9, precision)).thenReturn(-0.9463000876874145);
        when(math.cos(-1.9, precision)).thenReturn(-0.32328956686350335);

        when(math.sin(-1.95, precision)).thenReturn(-0.9289597150038693);
        when(math.cos(-1.95, precision)).thenReturn(-0.3701808313512869);
        when(math.sin(-2.1, precision)).thenReturn(-0.8632093666488737);
        when(math.cos(-2.1, precision)).thenReturn(-0.5048461045998576);

        when(math.sin(-2.2, precision)).thenReturn(-0.8084964038195901);
        when(math.cos(-2.2, precision)).thenReturn(-0.5885011172553458);
        when(math.sin(-2.5, precision)).thenReturn(-0.5984721441039564);
        when(math.cos(-2.5, precision)).thenReturn(-0.8011436155469337);
        when(math.sin(-2.8, precision)).thenReturn(-0.3349881501559051);
        when(math.cos(-2.8, precision)).thenReturn(-0.9422223406686581);
        when(math.sin(-3.1, precision)).thenReturn(-0.04158066243329049);
        when(math.cos(-3.1, precision)).thenReturn(-0.9991351502732795);

        when(math.sin(-3.2, precision)).thenReturn(0.058374143427580086);
        when(math.cos(-3.2, precision)).thenReturn(-0.9982947757947531);
        when(math.sin(-3.5, precision)).thenReturn(0.35078322768961984);
        when(math.cos(-3.5, precision)).thenReturn(-0.9364566872907963);
        when(math.sin(-3.8, precision)).thenReturn(0.6118578909427189);
        when(math.cos(-3.8, precision)).thenReturn(-0.7909677119144168);
        when(math.sin(-4.2, precision)).thenReturn(0.8715757724135882);
        when(math.cos(-4.2, precision)).thenReturn(-0.4902608213406994);

        when(math.sin(-4.25, precision)).thenReturn(0.8949893582285835);
        when(math.cos(-4.25, precision)).thenReturn(-0.4460874899137928);

        when(math.sin(-4.3, precision)).thenReturn(0.9161659367494549);
        when(math.cos(-4.3, precision)).thenReturn(-0.40079917207997545);
        when(math.sin(-4.4, precision)).thenReturn(0.9516020738895161);
        when(math.cos(-4.4, precision)).thenReturn(-0.30733286997841935);
        when(math.sin(-4.5, precision)).thenReturn(0.977530117665097);
        when(math.cos(-4.5, precision)).thenReturn(-0.2107957994307797);
        when(math.sin(-4.6, precision)).thenReturn(0.9936910036334644);
        when(math.cos(-4.6, precision)).thenReturn(-0.11215252693505487);

        when(math.sin(-4.8, precision)).thenReturn(0.9961646088358407);
        when(math.cos(-4.8, precision)).thenReturn(0.0874989834394464);
        when(math.sin(-4.9, precision)).thenReturn(0.9824526126243325);
        when(math.cos(-4.9, precision)).thenReturn(0.18651236942257576);
        when(math.sin(-5.0, precision)).thenReturn(0.9589242746631385);
        when(math.cos(-5.0, precision)).thenReturn(0.28366218546322625);
        when(math.sin(-5.1, precision)).thenReturn(0.9258146823277325);
        when(math.cos(-5.1, precision)).thenReturn(0.37797774271298024);

        when(math.sin(-5.15, precision)).thenReturn(0.9057666414687044);
        when(math.cos(-5.15, precision)).thenReturn(0.4237768176794282);

        when(math.sin(-5.2, precision)).thenReturn(0.8834546557201531);
        when(math.cos(-5.2, precision)).thenReturn(0.4685166713003771);
        when(math.sin(-5.3, precision)).thenReturn(0.8322674422239013);
        when(math.cos(-5.3, precision)).thenReturn(0.5543743361791608);
        when(math.sin(-5.4, precision)).thenReturn(0.7727644875559871);
        when(math.cos(-5.4, precision)).thenReturn(0.6346928759426347);
        when(math.sin(-5.5, precision)).thenReturn(0.7055403255703919);
        when(math.cos(-5.5, precision)).thenReturn(0.70866977429126);
        when(math.sin(-5.6, precision)).thenReturn(0.6312666378723216);
        when(math.cos(-5.6, precision)).thenReturn(0.7755658785102496);

        when(math.sin(-5.65, precision)).thenReturn(0.5917155806310094);
        when(math.cos(-5.65, precision)).thenReturn(0.8061468052647157);

        when(math.sin(-5.7, precision)).thenReturn(0.5506855425976376);
        when(math.cos(-5.7, precision)).thenReturn(0.8347127848391598);
        when(math.sin(-5.8, precision)).thenReturn(0.46460217941375737);
        when(math.cos(-5.8, precision)).thenReturn(0.8855195169413189);
        when(math.sin(-6.0, precision)).thenReturn(0.27941549819892586);
        when(math.cos(-6.0, precision)).thenReturn(0.960170286650366);
        when(math.sin(-6.2, precision)).thenReturn(0.0830894028174964);
        when(math.cos(-6.2, precision)).thenReturn(0.9965420970232175);


        ILogFunctions lf = new LogFunctions(precision, math);
        ITrigonometricFunctions tf = new TrigonometricFunctions(precision, math);
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
}
