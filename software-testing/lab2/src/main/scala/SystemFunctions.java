import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class SystemFunctions implements ISystemFunctions, ILogged {
    private final IComplexFunctions functions;
    private final Logger logger;

    public SystemFunctions(IComplexFunctions functions){
        this.functions = functions;
        logger = new Logger(new String[]{"x", "system_val"}, "system_function.csv");
    }

    @Override
    public double calculate(double x) {
        return (x <= 0d) ? functions.first(x) : functions.second(x);
    }

    @Override
    public void writeLog(double from, double to, double step) {
        try {
            logger.Start();

            double cur = from;
            while (cur < to) {
                List<Double> values = Arrays.asList(cur, calculate(cur));
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
