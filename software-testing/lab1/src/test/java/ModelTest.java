import model.Point;
import model.Void;
import model.*;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.awt.*;

public class ModelTest {
    private Engine engine;
    private Void<Point> modelVoid;
    private Air air;

    @Before
    public void setUp(){
        engine = new Engine();
        air = new Air(100);
        modelVoid = new Void<>();
    }

    @Test
    public void testInitialStateOfEngineIsNotHummed(){
        Assert.assertFalse(engine.isHummed());
    }

    @Test
    public void testHumEngine(){
        engine.start();
        Assert.assertTrue(engine.isHummed());
    }

    @Test
    public void testColorOfInitializedVoid(){
        Assert.assertEquals(Color.BLACK, modelVoid.getColor());
    }

    @Test
    public void testVoidIsSowedWithoutPoints(){
        Assert.assertFalse(modelVoid.isSowed());
    }

    @Test
    public void testVoidNotSowedWithLittlePoints(){
        for (byte i = 30; i < 35; i++) {
            modelVoid.sowElement(new Point(i));
            Assert.assertFalse(modelVoid.isSowed());
        }
    }

    @Test
    public void testVoidSowedWithLotOfPoints(){
        for (byte i = 30; i < Byte.MAX_VALUE; i++) {
            modelVoid.sowElement(new Point(i));
        }

        Assert.assertTrue(modelVoid.isSowed());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testExceptionWithNegativeVolumeOnAirInitialization(){
        new Air(-1);
    }

    @Test
    public void testInitialStateOfAirIsSubtleHiss(){
        Assert.assertEquals(AirState.SubtleHiss, air.getState());
    }

    @Test
    public void testAbsorbAirLikeSubtleHiss(){
        air.onAbsorb(5);
        Assert.assertEquals(AirState.SubtleHiss, air.getState());
    }

    @Test
    public void testAbsorbAirLikeRoar() {
        air.onAbsorb(100);
        Assert.assertEquals(AirState.Roar, air.getState());
    }

    @Test
    public void testLargeAirVolumeLeakIntoVoid(){
        air = new Air(100);
        Assert.assertEquals(AirState.SubtleHiss, air.getState());
        Assert.assertFalse(air.isAbsorbed());

        modelVoid.suckAnObject(air);

        Assert.assertEquals(AirState.Roar, air.getState());
        Assert.assertTrue(air.isAbsorbed());
    }

    @Test
    public void testSmallAirVolumeLeakIntoVoid(){
        air = new Air(2);
        Assert.assertEquals(AirState.SubtleHiss, air.getState());
        Assert.assertFalse(air.isAbsorbed());

        modelVoid.suckAnObject(air);

        Assert.assertEquals(AirState.SubtleHiss, air.getState());
        Assert.assertTrue(air.isAbsorbed());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testPointCreationWithNegativeBrightness(){
        new Point((byte) -1);
    }

    @Test
    public void testPointIncrediblyBrightness(){
        Point point = new Point(Byte.MAX_VALUE);
        Assert.assertEquals(Point.BrightnessType.IncrediblyHigh, point.getBrightness());
        Assert.assertTrue(point.isShiny());
    }

    @Test
    public void testPointIsNotIncrediblyBrightness(){
        for (byte i = 0; i < Byte.MAX_VALUE / 2; i++){
            Point point = new Point(i);
            Assert.assertNotEquals(Point.BrightnessType.IncrediblyHigh, point.getBrightness());
            Assert.assertTrue(point.isShiny());
        }
    }

    @Test(expected = IllegalArgumentException.class)
    public void testInitPersonWithNegativeWeight(){
        new Person("Форд", -1);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testInitPersonWithZeroWeight(){
        new Person("Форд", 0);
    }

    @Test
    public void testPersonFlewOutIntoVoid(){
        Person person = new Person("Форд", 65);
        Assert.assertFalse(person.isAbsorbed());
        Assert.assertEquals(Person.PersonCondition.AllRight, person.getCondition());

        modelVoid.suckAnObject(person);

        Assert.assertTrue(person.isAbsorbed());
        Assert.assertEquals(Person.PersonCondition.FlewOutLikeConfetti, person.getCondition());
    }

    @Test
    public void testFatPersonRippedToPieces(){
        Person person = new Person("Форд", 120);
        Assert.assertFalse(person.isAbsorbed());
        Assert.assertEquals(Person.PersonCondition.AllRight, person.getCondition());

        modelVoid.suckAnObject(person);

        Assert.assertTrue(person.isAbsorbed());
        Assert.assertEquals(Person.PersonCondition.RippedToPieces, person.getCondition());
    }
}
