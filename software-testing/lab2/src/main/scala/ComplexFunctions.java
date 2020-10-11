import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class ComplexFunctions implements IComplexFunctions, ILogged {
    private final ITrigonometricFunctions tf;
    private final ILogFunctions lf;
    private final Logger logger;

    public ComplexFunctions(ITrigonometricFunctions trigonometricFunctions, ILogFunctions logFunctions){
        this.tf = trigonometricFunctions;
        this.lf = logFunctions;
        logger = new Logger(new String[]{ "x", "first", "second"}, "complex_functions.csv");
    }

    @Override
    public double first(double x) {
        return (((((tf.cot(x) + tf.cos(x)) - (tf.cot(x) * tf.csc(x))) - tf.tan(x)) * (tf.csc(x) + (tf.cos(x) * tf.csc(x)))) + ((( Math.pow(tf.csc(x), 2)) + (tf.sec(x) * tf.cos(x))) * (tf.cos(x) + tf.sec(x))));
    }

    @Override
    public double second(double x) {
        return (((((Math.pow(lf.ln(x), 3)) * lf.log_5(x)) - lf.log_10(x)) * (Math.pow(lf.log_2(x), 3))) + ((lf.log_3(x) + lf.log_10(x)) / lf.log_2(x)));
    }

    @Override
    public void writeLog(double from, double to, double step) {
        try {
            logger.Start();

            double cur = from;
            while (cur < to) {
                List<Double> values = Arrays.asList(cur, first(cur), second(cur));
                logger.write(values);
                cur += step;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        catch (IllegalArgumentException e){
            System.err.println(e.getMessage());
        }
        finally {
            logger.close();
        }
    }
}
