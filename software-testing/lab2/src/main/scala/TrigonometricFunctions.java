import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class TrigonometricFunctions implements ITrigonometricFunctions, ILogged {
    private final double precision;
    private final LightMath math;
    private final Logger logger;

    public TrigonometricFunctions(double precision, LightMath math) {
        this.precision = precision;
        this.math = math;
        logger = new Logger(new String[]{ "x", "sin", "cos", "tan", "cot", "csc", "sec"}, "trig_functions.csv");
    }

    @Override
    public double sin(double x) {
        return math.sin(x, precision);
    }

    @Override
    public double cos(double x) {
        return math.cos(x, precision);
    }

    @Override
    public double tan(double x) {
        return sin(x) / cos(x);
    }

    @Override
    public double cot(double x) {
        return cos(x) / sin(x);
    }

    @Override
    public double csc(double x) {
        return 1 / sin(x);
    }

    @Override
    public double sec(double x) {
        return 1 / cos(x);
    }

    @Override
    public void writeLog(double from, double to, double step) {
        try {
            logger.Start();

            double cur = from;
            while (cur < to) {
                List<Double> values = Arrays.asList(cur, sin(cur), cos(cur), tan(cur), cot(cur), csc(cur), sec(cur));
                logger.write(values);
                cur += step;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        finally {
            logger.close();
        }
    }
}
