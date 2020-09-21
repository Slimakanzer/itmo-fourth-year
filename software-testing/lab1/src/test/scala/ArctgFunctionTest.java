import org.junit.Assert;
import org.junit.Test;

public class ArctgFunctionTest {
    @Test
    public void testRightBorder(){
        Assert.assertEquals("Right border of arctg (45°)", Math.PI / 4, MyMath.arctg(1.0), MyMath.Precision());
    }

    @Test
    public void testLeftBorder(){
        Assert.assertEquals("Left border of arctg (-45°)", -Math.PI / 4, MyMath.arctg(-1.0), MyMath.Precision());
    }

    @Test
    public void testZeroValue(){
        Assert.assertEquals("Zero value of arctg (intersection with OX)", 0, MyMath.arctg(0), MyMath.Precision());
    }

    @Test
    public void testPositiveXValues(){
        Assert.assertEquals("arctg with 30°", Math.PI / 6, MyMath.arctg(1 / Math.sqrt(3)), MyMath.Precision());
        Assert.assertEquals("arctg with 15°", Math.PI / 6 / 2, MyMath.arctg(2 - Math.sqrt(3)), MyMath.Precision());
    }

    @Test
    public void testNegativeXValues(){
        Assert.assertEquals("arctg with -30°", -Math.PI / 6, MyMath.arctg(-1 / Math.sqrt(3)), MyMath.Precision());
        Assert.assertEquals("arctg with -15°", -Math.PI / 6 / 2, MyMath.arctg(-2 + Math.sqrt(3)), MyMath.Precision());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testOutOfBoundsRightBorder(){
        MyMath.arctg(1.0 + Math.ulp(1.0));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testOutOfBoundsLeftBorder(){
        MyMath.arctg(-1.0 - Math.ulp(-1.0));
    }
}
