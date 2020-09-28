import org.junit.Assert;
import org.junit.Test;

public class ArctgFunctionTest {

    @Test
    public void testFirstRegionRightBorder(){
        Assert.assertEquals(0.46364760900, MyMath.arctg(0.5), MyMath.Precision());
    }

    @Test
    public void testFirstRegionPositiveValue(){
        Assert.assertEquals(0.24497866312, MyMath.arctg(0.25), MyMath.Precision());
        Assert.assertEquals("arctg with 15°", Math.PI / 6 / 2, MyMath.arctg(2 - Math.sqrt(3)), MyMath.Precision());
    }

    @Test
    public void testFirstRegionZeroValue(){
        Assert.assertEquals("Zero value of arctg (intersection with OX)", 0, MyMath.arctg(0), MyMath.Precision());
    }

    @Test
    public void testFirstRegionNegativeValue(){
        Assert.assertEquals(-0.24497866312, MyMath.arctg(-0.25), MyMath.Precision());
        Assert.assertEquals("arctg with -15°", -Math.PI / 6 / 2, MyMath.arctg(-2 + Math.sqrt(3)), MyMath.Precision());
    }

    @Test
    public void testFirstRegionLeftBorder(){
        Assert.assertEquals(-0.46364760900, MyMath.arctg(-0.5), MyMath.Precision());
    }

    @Test
    public void testSecondRegionValue(){
        Assert.assertEquals("arctg with 30°", Math.PI / 6, MyMath.arctg(1 / Math.sqrt(3)), MyMath.Precision());
    }

    @Test
    public void testSecondRegionRightBorder(){
        Assert.assertEquals("Right border of arctg (45°)", Math.PI / 4, MyMath.arctg(1.0), MyMath.Precision());
    }

    @Test
    public void testThirdRegionValue(){
        Assert.assertEquals("arctg with -30°", -Math.PI / 6, MyMath.arctg(-1 / Math.sqrt(3)), MyMath.Precision());
    }

    @Test
    public void testThirdRegionLeftBorder(){
        Assert.assertEquals("Left border of arctg (-45°)", -Math.PI / 4, MyMath.arctg(-1.0), MyMath.Precision());
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
