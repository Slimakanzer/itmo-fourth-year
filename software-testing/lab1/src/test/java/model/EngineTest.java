package model;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class EngineTest {
    private Engine engine;

    @Before
    public void setUp(){
        engine = new Engine();
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
}
