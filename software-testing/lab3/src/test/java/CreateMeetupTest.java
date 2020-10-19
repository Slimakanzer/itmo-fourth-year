import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.Keys;

import java.util.concurrent.TimeUnit;

import static org.junit.Assert.*;

public class CreateMeetupTest extends SeleniumTest {
    private static final String STEP_ONE = "STEP 1 OF 7";
    private static final String STEP_TWO = "STEP 2 OF 7";
    private static final String STEP_THREE = "STEP 3 OF 7";
    private static final String STEP_FOUR = "STEP 4 OF 7";
    private static final String STEP_FIVE = "STEP 5 OF 7";

    private static final String NEXT_BUTTON = "//*[@id=\"gtmStartFlow_nextButton\"]";
    private static final String PREV_BUTTON = "//*[@id=\"gtmStartFlow_backArrow\"]";
    private static final String FINAL_BUTTON = "//*[@id=\"gtmStartFlow_continueToPayment\"]";

    private String getStepText() {
        return waitUntilReady("//*[@id=\"mupMain\"]/div/div/div/div[1]/div[2]").getText();
    }

    @Test
    public void createMeetupFirstStepDefaultCity() {
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[2]/div/div[1]/div/a").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div[1]/div/div/div/a").click();

        assertEquals(STEP_ONE, getStepText());
        waitUntilClickable(NEXT_BUTTON).click();
    }

    @Test
    public void createMeetupFirstStepSelectCity() {
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[2]/div/div[1]/div/a").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div[1]/div/div/div/a").click();

        assertEquals(STEP_ONE, getStepText());

        waitUntilClickable("//*[@id=\"gtmStartFlow_changeLocationButton\"]").click();
        waitUntilClickable("//*[@id=\"venueSearch\"]").sendKeys("Saint-Petersburg");
        waitUntilClickable("//*[@id=\"typeaheadItem-0\"]/button").click();

        waitUntilClickable(NEXT_BUTTON).click();
    }

    @Test
    public void createMeetupSecondStepSelectFirstElement(){
        createMeetupFirstStepDefaultCity();

        assertEquals(STEP_TWO, getStepText());

        assertFalse(waitUntilReady(NEXT_BUTTON).isEnabled());
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[1]/button").click();
        assertTrue(waitUntilReady(NEXT_BUTTON).isEnabled());

        waitUntilClickable(NEXT_BUTTON).click();
    }

    @Test
    public void createMeetupSecondStepSearchExistedElements(){
        createMeetupFirstStepDefaultCity();

        assertEquals(STEP_TWO, getStepText());

        waitUntilClickable("//*[@id=\"topics-searchResultInput\"]").clear();
        waitUntilClickable("//*[@id=\"topics-searchResultInput\"]").sendKeys(".net");
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[1]/button").click();

        assertTrue(waitUntilReady(NEXT_BUTTON).isEnabled());
        var elements = driver.findElements(By.xpath("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li"));
        assertEquals(15, elements.size());

        waitUntilClickable(NEXT_BUTTON).click();
    }

    @Test
    public void createMeetupSecondStepSelectMultipleElement(){
        createMeetupFirstStepDefaultCity();

        assertEquals(STEP_TWO, getStepText());
        assertFalse(waitUntilReady("//*[@id=\"gtmStartFlow_nextButton\"]").isEnabled());
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[1]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[2]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[3]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[4]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[5]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[6]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[7]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[8]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[9]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[10]/button").click();

        assertTrue(waitUntilReady(NEXT_BUTTON).isEnabled());
    }

    @Test
    public void createMeetupSecondStepSelectMoreThanMaxElement(){
        createMeetupFirstStepDefaultCity();

        waitUntilClickable("//*[@id=\"topics-searchResultInput\"]");
        assertEquals(STEP_TWO, getStepText());

        assertFalse(waitUntilReady(NEXT_BUTTON).isEnabled());
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[1]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[2]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[3]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[4]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[5]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[6]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[7]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[8]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[9]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[10]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[11]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[12]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[13]/button").click();

        waitUntilClickable("//*[@id=\"gtmStartFlow_showMoreTopics\"]/span/span").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[14]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[15]/button").click();
        waitUntilClickable("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li[16]/button").click();

        var warningText = waitUntilReady("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/p[2]/span").getText();
        assertEquals("You can only choose up to 15 topics.", warningText);
        assertTrue(waitUntilReady(NEXT_BUTTON).isEnabled());
    }

    @Test
    public void createMeetupSecondStepSearchNonExistedElements(){
        createMeetupFirstStepDefaultCity();

        assertEquals(STEP_TWO, getStepText());

        waitUntilReady("//*[@id=\"topics-searchResultInput\"]").clear();
        waitUntilReady("//*[@id=\"topics-searchResultInput\"]").sendKeys("asdasdasd");
        waitUntilReady("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul").click();

        var elements = driver.findElements(By.xpath("//*[@id=\"mupMain\"]/div/div/div/form/div/div/div/div/ul/li"));
        assertEquals(0, elements.size());
        assertFalse(waitUntilReady(NEXT_BUTTON).isEnabled());
    }

    @Test
    public void createMeetupThirdStepDefaultName(){
        createMeetupSecondStepSelectFirstElement();

        assertEquals(STEP_THREE, getStepText());
        assertTrue(waitUntilClickable(NEXT_BUTTON).isEnabled());
        waitUntilClickable(NEXT_BUTTON).click();
    }

    @Test
    public void createMeetupThirdStepEmptyName() throws InterruptedException {
        createMeetupSecondStepSelectFirstElement();

        assertEquals(STEP_THREE, getStepText());
        assertTrue(waitUntilClickable(NEXT_BUTTON).isEnabled());

        waitUntilClickable("//*[@id=\"name\"]").sendKeys(Keys.CONTROL + "a");
        waitUntilClickable("//*[@id=\"name\"]").sendKeys(Keys.DELETE);
        TimeUnit.SECONDS.sleep(2);
        assertFalse(waitUntilReady(NEXT_BUTTON).isEnabled());
    }

    @Test
    public void createMeetupThirdStepToLargeName() throws InterruptedException {
        createMeetupSecondStepSelectFirstElement();

        assertEquals(STEP_THREE, getStepText());
        assertTrue(waitUntilClickable(NEXT_BUTTON).isEnabled());

        waitUntilClickable("//*[@id=\"name\"]").sendKeys("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

        TimeUnit.SECONDS.sleep(2);
        assertFalse(waitUntilReady(NEXT_BUTTON).isEnabled());
    }

    @Test
    public void createMeetupFourthStepSetSimpleDescription(){
        createMeetupThirdStepDefaultName();

        assertEquals(STEP_FOUR, getStepText());
        waitUntilClickable("//*[@id=\"description\"]").sendKeys("Hello, it is me, i will forget about you forever. YAHAHAHAHA");
        assertTrue(waitUntilClickable(NEXT_BUTTON).isEnabled());

        waitUntilClickable(NEXT_BUTTON).click();
    }

    @Test
    public void createMeetupFifthStep(){
        createMeetupFourthStepSetSimpleDescription();

        assertEquals(STEP_FIVE, getStepText());
        waitUntilClickable(FINAL_BUTTON);
    }

    @Test
    public void backButtonOnStep(){
        createMeetupFifthStep();

        assertEquals(STEP_FIVE, getStepText());
        waitUntilClickable(PREV_BUTTON).click();
        assertEquals(STEP_FOUR, getStepText());
        waitUntilClickable(PREV_BUTTON).click();
        assertEquals(STEP_THREE, getStepText());
        waitUntilClickable(PREV_BUTTON).click();
        assertEquals(STEP_TWO, getStepText());
    }

    @Test
    public void saveAndExitFromCreatingMeetupAndReturn() {
        createMeetupFifthStep();
        assertEquals(STEP_FIVE, getStepText());

        waitUntilClickable("//*[@id=\"gtmStartFlow_saveAndExitButton\"]").click();
        waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[2]/div/div[2]/a[1]").click();

        waitUntilReady("//*[@id=\"mupMain\"]/div/div/div/div[1]/div[2]\"");
        assertEquals(STEP_FIVE, getStepText());
    }
}
