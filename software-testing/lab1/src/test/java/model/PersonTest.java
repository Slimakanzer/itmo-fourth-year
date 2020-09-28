package model;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class PersonTest {
    private Void<Point> modelVoid;

    @Before
    public void setUp(){
        modelVoid = new Void<>();
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
