import static org.junit.Assert.assertEquals;

public class IntegrationTest {
    protected ISystemFunctions systemFunctions;
    protected static final double Precision = 0.01d;
    protected static final double PuncturePointLimit = 10000d;

    protected static void precisionAssertEquals(String message, double expected, double value){
        assertEquals(message, expected, value, Precision);
    }
}
