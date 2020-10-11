import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class LogFunctions implements ILogFunctions, ILogged {
    private final double precision;
    private final LightMath math;
    private final Logger logger;

    public LogFunctions(double precision, LightMath math) {
        this.precision = precision;
        this.math = math;
        logger = new Logger(new String[]{ "x", "ln", "log_2", "log_3", "log_5", "log_10"}, "log_functions.csv");
    }

    @Override
    public double ln(double x) {
        return math.ln(x, precision);
    }

    @Override
    public double log_2(double x){
        return ln(x) / ln(2d);
    }

    @Override
    public double log_3(double x){
        return ln(x) / ln(3d);
    }

    @Override
    public double log_5(double x) {
        return ln(x) / ln(5d);
    }

    @Override
    public double log_10(double x) {
        return ln(x) / ln(10d);
    }

    @Override
    public void writeLog(double from, double to, double step) {
        try {
            logger.Start();

            double cur = from;
            while (cur < to) {
                 List<Double> values = Arrays.asList(cur, ln(cur), log_2(cur), log_3(cur), log_5(cur), log_10(cur));
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
