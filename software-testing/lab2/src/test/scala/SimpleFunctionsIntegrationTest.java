import org.junit.Before;
import org.junit.Test;

import static org.mockito.Mockito.*;
import static org.junit.Assert.*;

public class SimpleFunctionsIntegrationTest extends IntegrationTest {

    @Before
    public void mockSimpleFunctions() {
        ITrigonometricFunctions tf = mock(TrigonometricFunctions.class);
        ILogFunctions lf = mock(LogFunctions.class);

        when(lf.ln(0.02)).thenReturn(-3.912023005428146);
        when(lf.log_2(0.02)).thenReturn(-5.643856189774724);
        when(lf.log_3(0.02)).thenReturn(-3.5608767950073115);
        when(lf.log_5(0.02)).thenReturn(-2.4306765580733933);
        when(lf.log_10(0.02)).thenReturn(-1.6989700043360185);
        when(lf.ln(0.1)).thenReturn(-2.3025850929940455);
        when(lf.log_2(0.1)).thenReturn(-3.321928094887362);
        when(lf.log_3(0.1)).thenReturn(-2.0959032742893844);
        when(lf.log_5(0.1)).thenReturn(-1.430676558073393);
        when(lf.log_10(0.1)).thenReturn(-0.9999999999999998);
        when(lf.ln(0.2)).thenReturn(-1.6094379124341003);
        when(lf.log_2(0.2)).thenReturn(-2.321928094887362);
        when(lf.log_3(0.2)).thenReturn(-1.4649735207179269);
        when(lf.log_5(0.2)).thenReturn(-1.0);
        when(lf.log_10(0.2)).thenReturn(-0.6989700043360187);
        when(lf.ln(0.3)).thenReturn(-1.2039728043259361);
        when(lf.log_2(0.3)).thenReturn(-1.7369655941662063);
        when(lf.log_3(0.3)).thenReturn(-1.0959032742893846);
        when(lf.log_5(0.3)).thenReturn(-0.7480703635874079);
        when(lf.log_10(0.3)).thenReturn(-0.5228787452803376);
        when(lf.ln(0.4)).thenReturn(-0.916290731874155);
        when(lf.log_2(0.4)).thenReturn(-1.3219280948873622);
        when(lf.log_3(0.4)).thenReturn(-0.8340437671464696);
        when(lf.log_5(0.4)).thenReturn(-0.5693234419266069);
        when(lf.log_10(0.4)).thenReturn(-0.39794000867203755);
        when(lf.ln(0.5)).thenReturn(-0.6931471805599453);
        when(lf.log_2(0.5)).thenReturn(-1.0);
        when(lf.log_3(0.5)).thenReturn(-0.6309297535714574);
        when(lf.log_5(0.5)).thenReturn(-0.43067655807339306);
        when(lf.log_10(0.5)).thenReturn(-0.30102999566398114);
        when(lf.ln(0.55)).thenReturn(-0.5978370007556204);
        when(lf.log_2(0.55)).thenReturn(-0.8624964762500651);
        when(lf.log_3(0.55)).thenReturn(-0.5441746892167039);
        when(lf.log_5(0.55)).thenReturn(-0.371457013741808);
        when(lf.log_10(0.55)).thenReturn(-0.2596373105057561);

        when(lf.ln(0.6)).thenReturn(-0.5108256237659907);
        when(lf.log_2(0.6)).thenReturn(-0.7369655941662062);
        when(lf.log_3(0.6)).thenReturn(-0.4649735207179272);
        when(lf.log_5(0.6)).thenReturn(-0.31739380551401475);
        when(lf.log_10(0.6)).thenReturn(-0.22184874961635637);
        when(lf.ln(0.7)).thenReturn(-0.35667494393873245);
        when(lf.log_2(0.7)).thenReturn(-0.5145731728297583);
        when(lf.log_3(0.7)).thenReturn(-0.32465952512796237);
        when(lf.log_5(0.7)).thenReturn(-0.22161460295122554);
        when(lf.log_10(0.7)).thenReturn(-0.1549019599857432);
        when(lf.ln(0.8)).thenReturn(-0.2231435513142097);
        when(lf.log_2(0.8)).thenReturn(-0.3219280948873623);
        when(lf.log_3(0.8)).thenReturn(-0.20311401357501224);
        when(lf.log_5(0.8)).thenReturn(-0.1386468838532139);
        when(lf.log_10(0.8)).thenReturn(-0.09691001300805638);
        when(lf.ln(0.9)).thenReturn(-0.10536051565782628);
        when(lf.log_2(0.9)).thenReturn(-0.15200309344504997);
        when(lf.log_3(0.9)).thenReturn(-0.09590327428938458);
        when(lf.log_5(0.9)).thenReturn(-0.06546416910142246);
        when(lf.log_10(0.9)).thenReturn(-0.045757490560675115);

        when(lf.ln(1.0)).thenReturn(0.0);
        when(lf.log_2(1.0)).thenReturn(0.0);
        when(lf.log_3(1.0)).thenReturn(0.0);
        when(lf.log_5(1.0)).thenReturn(0.0);
        when(lf.log_10(1.0)).thenReturn(0.0);

        when(lf.ln(1.05)).thenReturn(0.04879016416943204);
        when(lf.log_2(1.05)).thenReturn(0.070389327891398);
        when(lf.log_3(1.05)).thenReturn(0.04441072130058025);
        when(lf.log_5(1.05)).thenReturn(0.030315033461366776);
        when(lf.log_10(1.05)).thenReturn(0.02118929906993809);
        when(lf.ln(1.1)).thenReturn(0.09531017980432493);
        when(lf.log_2(1.1)).thenReturn(0.13750352374993502);
        when(lf.log_3(1.1)).thenReturn(0.08675506435475354);
        when(lf.log_5(1.1)).thenReturn(0.05921954433158507);
        when(lf.log_10(1.1)).thenReturn(0.04139268515822507);
        when(lf.ln(1.15)).thenReturn(0.13976194237515863);
        when(lf.log_2(1.15)).thenReturn(0.20163386116965043);
        when(lf.log_3(1.15)).thenReturn(0.127216802339429);
        when(lf.log_5(1.15)).thenReturn(0.08683897731959343);
        when(lf.log_10(1.15)).thenReturn(0.06069784035361165);
        when(lf.ln(1.2)).thenReturn(0.1823215567939546);
        when(lf.log_2(1.2)).thenReturn(0.2630344058337938);
        when(lf.log_3(1.2)).thenReturn(0.16595623285353023);
        when(lf.log_5(1.2)).thenReturn(0.11328275255937834);
        when(lf.log_10(1.2)).thenReturn(0.0791812460476248);

        when(lf.ln(1.3)).thenReturn(0.26236426446749106);
        when(lf.log_2(1.3)).thenReturn(0.37851162325372983);
        when(lf.log_3(1.3)).thenReturn(0.23881424518340807);
        when(lf.log_5(1.3)).thenReturn(0.16301608309368926);
        when(lf.log_10(1.3)).thenReturn(0.11394335230683676);
        when(lf.ln(1.5)).thenReturn(0.4054651081081644);
        when(lf.log_2(1.5)).thenReturn(0.5849625007211562);
        when(lf.log_3(1.5)).thenReturn(0.3690702464285425);
        when(lf.log_5(1.5)).thenReturn(0.25192963641259225);
        when(lf.log_10(1.5)).thenReturn(0.17609125905568124);
        when(lf.ln(1.75)).thenReturn(0.5596157879354227);
        when(lf.log_2(1.75)).thenReturn(0.8073549220576041);
        when(lf.log_3(1.75)).thenReturn(0.5093842420185073);
        when(lf.log_5(1.75)).thenReturn(0.34770883897538146);
        when(lf.log_10(1.75)).thenReturn(0.24303804868629442);

        when(lf.ln(1.8)).thenReturn(0.5877866649021191);
        when(lf.log_2(1.8)).thenReturn(0.8479969065549501);
        when(lf.log_3(1.8)).thenReturn(0.5350264792820728);
        when(lf.log_5(1.8)).thenReturn(0.36521238897197067);
        when(lf.log_10(1.8)).thenReturn(0.25527250510330607);
        when(lf.ln(1.9)).thenReturn(0.6418538861723947);
        when(lf.log_2(1.9)).thenReturn(0.925999418556223);
        when(lf.log_3(1.9)).thenReturn(0.5842405849569906);
        when(lf.log_5(1.9)).thenReturn(0.39880624236175743);
        when(lf.log_10(1.9)).thenReturn(0.2787536009528289);
        when(lf.ln(2.0)).thenReturn(0.6931471805599453);
        when(lf.log_2(2.0)).thenReturn(1.0);
        when(lf.log_3(2.0)).thenReturn(0.6309297535714574);
        when(lf.log_5(2.0)).thenReturn(0.43067655807339306);
        when(lf.log_10(2.0)).thenReturn(0.30102999566398114);

        when(lf.ln(2.0884971449233825358269495952366013421428061969691576000370777169)).thenReturn(0.7364447379076575);
        when(lf.log_2(2.0884971449233825358269495952366013421428061969691576000370777169)).thenReturn(1.0624651712681499);
        when(lf.log_3(2.0884971449233825358269495952366013421428061969691576000370777169)).thenReturn(0.6703408886864701);
        when(lf.log_5(2.0884971449233825358269495952366013421428061969691576000370777169)).thenReturn(0.45757884303462487);
        when(lf.log_10(2.0884971449233825358269495952366013421428061969691576000370777169)).thenReturn(0.3198338858999822);

        when(lf.ln(2.1)).thenReturn(0.7419373447293773);
        when(lf.log_2(2.1)).thenReturn(1.070389327891398);
        when(lf.log_3(2.1)).thenReturn(0.6753404748720376);
        when(lf.log_5(2.1)).thenReturn(0.4609915915347598);
        when(lf.log_10(2.1)).thenReturn(0.32221929473391925);
        when(lf.ln(2.5)).thenReturn(0.9162907318741551);
        when(lf.log_2(2.5)).thenReturn(1.3219280948873624);
        when(lf.log_3(2.5)).thenReturn(0.8340437671464697);
        when(lf.log_5(2.5)).thenReturn(0.569323441926607);
        when(lf.log_10(2.5)).thenReturn(0.3979400086720376);
        when(lf.ln(3.0)).thenReturn(1.0986122886681098);
        when(lf.log_2(3.0)).thenReturn(1.5849625007211563);
        when(lf.log_3(3.0)).thenReturn(1.0);
        when(lf.log_5(3.0)).thenReturn(0.6826061944859854);
        when(lf.log_10(3.0)).thenReturn(0.47712125471966244);
        when(lf.ln(5.0)).thenReturn(1.6094379124341003);
        when(lf.log_2(5.0)).thenReturn(2.321928094887362);
        when(lf.log_3(5.0)).thenReturn(1.4649735207179269);
        when(lf.log_5(5.0)).thenReturn(1.0);
        when(lf.log_10(5.0)).thenReturn(0.6989700043360187);
        when(lf.ln(10.0)).thenReturn(2.302585092994046);
        when(lf.log_2(10.0)).thenReturn(3.3219280948873626);
        when(lf.log_3(10.0)).thenReturn(2.095903274289385);
        when(lf.log_5(10.0)).thenReturn(1.4306765580733933);
        when(lf.log_10(10.0)).thenReturn(1.0);
        when(lf.ln(20.0)).thenReturn(2.995732273553991);
        when(lf.log_2(20.0)).thenReturn(4.321928094887363);
        when(lf.log_3(20.0)).thenReturn(2.7268330278608417);
        when(lf.log_5(20.0)).thenReturn(1.8613531161467862);
        when(lf.log_10(20.0)).thenReturn(1.301029995663981);
        when(lf.ln(100.0)).thenReturn(4.605170185988092);
        when(lf.log_2(100.0)).thenReturn(6.643856189774725);
        when(lf.log_3(100.0)).thenReturn(4.19180654857877);
        when(lf.log_5(100.0)).thenReturn(2.8613531161467867);
        when(lf.log_10(100.0)).thenReturn(2.0);


        /* negative region */
        when(tf.sin(0.0)).thenReturn(0.0);
        when(tf.cos(0.0)).thenReturn(1.0);
        when(tf.tan(0.0)).thenReturn(0.0);
        when(tf.cot(0.0)).thenReturn(Double.NaN);
        when(tf.csc(0.0)).thenReturn(Double.NaN);
        when(tf.sec(0.0)).thenReturn(1.0);
        for (int i = 1; i < 20; i++) {
            when(tf.sin(-Math.PI / 2 * i)).thenReturn(0.0);
            when(tf.cos(-Math.PI / 2 * i)).thenReturn(1.0);
            when(tf.tan(-Math.PI / 2 * i)).thenReturn(0.0);
            when(tf.cot(-Math.PI / 2 * i)).thenReturn(Double.NaN);
            when(tf.csc(-Math.PI / 2 * i)).thenReturn(Double.NaN);
            when(tf.sec(-Math.PI / 2 * i)).thenReturn(1.0);
        }

        when(tf.sin(-0.4)).thenReturn(-0.3894183423086505);
        when(tf.cos(-0.4)).thenReturn(0.9210609940028851);
        when(tf.tan(-0.4)).thenReturn(-0.4227932187381618);
        when(tf.cot(-0.4)).thenReturn(-2.3652224200391103);
        when(tf.csc(-0.4)).thenReturn(-2.567932455547783);
        when(tf.sec(-0.4)).thenReturn(1.0857044283832387);
        when(tf.sin(-0.7)).thenReturn(-0.644217687237691);
        when(tf.cos(-0.7)).thenReturn(0.7648421872844885);
        when(tf.tan(-0.7)).thenReturn(-0.8422883804630794);
        when(tf.cot(-0.7)).thenReturn(-1.1872418321266796);
        when(tf.csc(-0.7)).thenReturn(-1.552270326957104);
        when(tf.sec(-0.7)).thenReturn(1.3074592597335937);
        when(tf.sin(-1.15)).thenReturn(-0.912763940260521);
        when(tf.cos(-1.15)).thenReturn(0.4084874408841574);
        when(tf.tan(-1.15)).thenReturn(-2.2344969487553255);
        when(tf.cot(-1.15)).thenReturn(-0.4475280221604361);
        when(tf.csc(-1.15)).thenReturn(-1.0955735167567862);
        when(tf.sec(-1.15)).thenReturn(2.44805568033018);

        when(tf.sin(-1.2)).thenReturn(-0.9320390859672263);
        when(tf.cos(-1.2)).thenReturn(0.3623577544766736);
        when(tf.tan(-1.2)).thenReturn(-2.5721516221263188);
        when(tf.cot(-1.2)).thenReturn(-0.38877956936820496);
        when(tf.csc(-1.2)).thenReturn(-1.0729163777098973);
        when(tf.sec(-1.2)).thenReturn(2.759703601332406);
        when(tf.sin(-1.25)).thenReturn(-0.9489846193555862);
        when(tf.cos(-1.25)).thenReturn(0.3153223623952687);
        when(tf.tan(-1.25)).thenReturn(-3.0095696738628313);
        when(tf.cot(-1.25)).thenReturn(-0.3322734172545286);
        when(tf.csc(-1.25)).thenReturn(-1.053757858245433);
        when(tf.sec(-1.25)).thenReturn(3.171357693770103);

        when(tf.sin(-1.3)).thenReturn(-0.963558185417193);
        when(tf.cos(-1.3)).thenReturn(0.26749882862458735);
        when(tf.tan(-1.3)).thenReturn(-3.6021024479679786);
        when(tf.cot(-1.3)).thenReturn(-0.27761564654112514);
        when(tf.csc(-1.3)).thenReturn(-1.0378200456748015);
        when(tf.sec(-1.3)).thenReturn(3.738334127075442);
        when(tf.sin(-1.4)).thenReturn(-0.9854497299884601);
        when(tf.cos(-1.4)).thenReturn(0.16996714290024104);
        when(tf.tan(-1.4)).thenReturn(-5.797883715482887);
        when(tf.cot(-1.4)).thenReturn(-0.17247672583180007);
        when(tf.csc(-1.4)).thenReturn(-1.0147651062948795);
        when(tf.sec(-1.4)).thenReturn(5.883490084827342);
        when(tf.sin(-1.5)).thenReturn(-0.9974949866040544);
        when(tf.cos(-1.5)).thenReturn(0.0707372016677029);
        when(tf.tan(-1.5)).thenReturn(-14.101419947171719);
        when(tf.cot(-1.5)).thenReturn(-0.07091484430265245);
        when(tf.csc(-1.5)).thenReturn(-1.0025113042467249);
        when(tf.sec(-1.5)).thenReturn(14.136832902969903);

        when(tf.sin(-1.7)).thenReturn(-0.9916648104524686);
        when(tf.cos(-1.7)).thenReturn(-0.12884449429552464);
        when(tf.tan(-1.7)).thenReturn(7.696602139459161);
        when(tf.cot(-1.7)).thenReturn(0.12992746433821378);
        when(tf.csc(-1.7)).thenReturn(-1.0084052488902255);
        when(tf.sec(-1.7)).thenReturn(-7.761293996050358);
        when(tf.sin(-1.8)).thenReturn(-0.9738476308781951);
        when(tf.cos(-1.8)).thenReturn(-0.2272020946930871);
        when(tf.tan(-1.8)).thenReturn(4.286261674628062);
        when(tf.cot(-1.8)).thenReturn(0.23330353485401106);
        when(tf.csc(-1.8)).thenReturn(-1.026854682696328);
        when(tf.sec(-1.8)).thenReturn(-4.4013678718536315);
        when(tf.sin(-1.9)).thenReturn(-0.9463000876874145);
        when(tf.cos(-1.9)).thenReturn(-0.32328956686350335);
        when(tf.tan(-1.9)).thenReturn(2.9270975146777736);
        when(tf.cot(-1.9)).thenReturn(0.3416353554965469);
        when(tf.csc(-1.9)).thenReturn(-1.056747233791152);
        when(tf.sec(-1.9)).thenReturn(-3.0932022016726934);

        when(tf.sin(-1.95)).thenReturn(-0.9289597150038693);
        when(tf.cos(-1.95)).thenReturn(-0.3701808313512869);
        when(tf.tan(-1.95)).thenReturn(2.509475468010723);
        when(tf.cot(-1.95)).thenReturn(0.3984896496289347);
        when(tf.csc(-1.95)).thenReturn(-1.0764729447883914);
        when(tf.sec(-1.95)).thenReturn(-2.70138244692373);
        when(tf.sin(-2.1)).thenReturn(-0.8632093666488737);
        when(tf.cos(-2.1)).thenReturn(-0.5048461045998576);
        when(tf.tan(-2.1)).thenReturn(1.7098465429045075);
        when(tf.cot(-2.1)).thenReturn(0.5848478064594647);
        when(tf.csc(-2.1)).thenReturn(-1.1584675035237058);
        when(tf.sec(-2.1)).thenReturn(-1.9808016559672235);

        when(tf.sin(-2.2)).thenReturn(-0.8084964038195901);
        when(tf.cos(-2.2)).thenReturn(-0.5885011172553458);
        when(tf.tan(-2.2)).thenReturn(1.3738230567687948);
        when(tf.cot(-2.2)).thenReturn(0.7278957760047939);
        when(tf.csc(-2.2)).thenReturn(-1.2368638812438584);
        when(tf.sec(-2.2)).thenReturn(-1.6992321181373529);
        when(tf.sin(-2.5)).thenReturn(-0.5984721441039564);
        when(tf.cos(-2.5)).thenReturn(-0.8011436155469337);
        when(tf.tan(-2.5)).thenReturn(0.7470222972386602);
        when(tf.cot(-2.5)).thenReturn(1.3386481283041514);
        when(tf.csc(-2.5)).thenReturn(-1.67092154555868);
        when(tf.sec(-2.5)).thenReturn(-1.2482156514688179);
        when(tf.sin(-2.8)).thenReturn(-0.3349881501559051);
        when(tf.cos(-2.8)).thenReturn(-0.9422223406686581);
        when(tf.tan(-2.8)).thenReturn(0.3555298316511761);
        when(tf.cot(-2.8)).thenReturn(2.812703494825543);
        when(tf.csc(-2.8)).thenReturn(-2.9851802206573432);
        when(tf.sec(-2.8)).thenReturn(-1.061320621298726);
        when(tf.sin(-3.1)).thenReturn(-0.04158066243329049);
        when(tf.cos(-3.1)).thenReturn(-0.9991351502732795);
        when(tf.tan(-3.1)).thenReturn(0.041616654585635904);
        when(tf.cot(-3.1)).thenReturn(24.0288415769285);
        when(tf.csc(-3.1)).thenReturn(-24.049640902290573);
        when(tf.sec(-3.1)).thenReturn(-1.0008655983392076);

        when(tf.sin(-3.2)).thenReturn(0.058374143427580086);
        when(tf.cos(-3.2)).thenReturn(-0.9982947757947531);
        when(tf.tan(-3.2)).thenReturn(-0.058473854459578645);
        when(tf.cot(-3.2)).thenReturn(-17.101660378678684);
        when(tf.csc(-3.2)).thenReturn(17.13087235687863);
        when(tf.sec(-3.2)).thenReturn(-1.00170813696174);
        when(tf.sin(-3.5)).thenReturn(0.35078322768961984);
        when(tf.cos(-3.5)).thenReturn(-0.9364566872907963);
        when(tf.tan(-3.5)).thenReturn(-0.3745856401585947);
        when(tf.cot(-3.5)).thenReturn(-2.669616484968866);
        when(tf.csc(-3.5)).thenReturn(2.850763437540464);
        when(tf.sec(-3.5)).thenReturn(-1.0678550471918107);
        when(tf.sin(-3.8)).thenReturn(0.6118578909427189);
        when(tf.cos(-3.8)).thenReturn(-0.7909677119144168);
        when(tf.tan(-3.8)).thenReturn(-0.7735560905031258);
        when(tf.cot(-3.8)).thenReturn(-1.2927310795906135);
        when(tf.csc(-3.8)).thenReturn(1.6343664350871603);
        when(tf.sec(-3.8)).thenReturn(-1.2642741099755543);
        when(tf.sin(-4.2)).thenReturn(0.8715757724135882);
        when(tf.cos(-4.2)).thenReturn(-0.4902608213406994);
        when(tf.tan(-4.2)).thenReturn(-1.7777797745088417);
        when(tf.cot(-4.2)).thenReturn(-0.5624993682225213);
        when(tf.csc(-4.2)).thenReturn(1.1473471746819859);
        when(tf.sec(-4.2)).thenReturn(-2.039730601489498);

        when(tf.sin(-4.25)).thenReturn(0.8949893582285835);
        when(tf.cos(-4.25)).thenReturn(-0.4460874899137928);
        when(tf.tan(-4.25)).thenReturn(-2.0063090278580593);
        when(tf.cot(-4.25)).thenReturn(-0.4984277028686865);
        when(tf.csc(-4.25)).thenReturn(1.1173317211047737);
        when(tf.sec(-4.25)).thenReturn(-2.2417127191646906);

        when(tf.sin(-4.3)).thenReturn(0.9161659367494549);
        when(tf.cos(-4.3)).thenReturn(-0.40079917207997545);
        when(tf.tan(-4.3)).thenReturn(-2.28584787736698);
        when(tf.cot(-4.3)).thenReturn(-0.4374744312171284);
        when(tf.csc(-4.3)).thenReturn(1.0915053265874382);
        when(tf.sec(-4.3)).thenReturn(-2.495015133914648);
        when(tf.sin(-4.4)).thenReturn(0.9516020738895161);
        when(tf.cos(-4.4)).thenReturn(-0.30733286997841935);
        when(tf.tan(-4.4)).thenReturn(-3.0963237806497457);
        when(tf.cot(-4.4)).thenReturn(-0.3229636403820003);
        when(tf.csc(-4.4)).thenReturn(1.0508594163867944);
        when(tf.sec(-4.4)).thenReturn(-3.253801001078144);
        when(tf.sin(-4.5)).thenReturn(0.977530117665097);
        when(tf.cos(-4.5)).thenReturn(-0.2107957994307797);
        when(tf.tan(-4.5)).thenReturn(-4.637332054551185);
        when(tf.cot(-4.5)).thenReturn(-0.21564123255279444);
        when(tf.csc(-4.5)).thenReturn(1.022986383671302);
        when(tf.sec(-4.5)).thenReturn(-4.743927548368325);
        when(tf.sin(-4.6)).thenReturn(0.9936910036334644);
        when(tf.cos(-4.6)).thenReturn(-0.11215252693505487);
        when(tf.tan(-4.6)).thenReturn(-8.860174895648045);
        when(tf.cot(-4.6)).thenReturn(-0.11286458921834393);
        when(tf.csc(-4.6)).thenReturn(1.0063490525157885);
        when(tf.sec(-4.6)).thenReturn(-8.916428611359587);

        when(tf.sin(-4.8)).thenReturn(0.9961646088358407);
        when(tf.cos(-4.8)).thenReturn(0.0874989834394464);
        when(tf.tan(-4.8)).thenReturn(11.384870654242922);
        when(tf.cot(-4.8)).thenReturn(0.08783586835282307);
        when(tf.csc(-4.8)).thenReturn(1.0038501580262338);
        when(tf.sec(-4.8)).thenReturn(11.428704205369987);
        when(tf.sin(-4.9)).thenReturn(0.9824526126243325);
        when(tf.cos(-4.9)).thenReturn(0.18651236942257576);
        when(tf.tan(-4.9)).thenReturn(5.267493065826737);
        when(tf.cot(-4.9)).thenReturn(0.1898436291236103);
        when(tf.csc(-4.9)).thenReturn(1.0178607977119576);
        when(tf.sec(-4.9)).thenReturn(5.361574693924608);
        when(tf.sin(-5.0)).thenReturn(0.9589242746631385);
        when(tf.cos(-5.0)).thenReturn(0.28366218546322625);
        when(tf.tan(-5.0)).thenReturn(3.380515006246586);
        when(tf.cot(-5.0)).thenReturn(0.2958129155327455);
        when(tf.csc(-5.0)).thenReturn(1.0428352127714058);
        when(tf.sec(-5.0)).thenReturn(3.5253200858160887);
        when(tf.sin(-5.1)).thenReturn(0.9258146823277325);
        when(tf.cos(-5.1)).thenReturn(0.37797774271298024);
        when(tf.tan(-5.1)).thenReturn(2.4493894155845988);
        when(tf.cot(-5.1)).thenReturn(0.408265012348528);
        when(tf.csc(-5.1)).thenReturn(1.080129770123916);
        when(tf.sec(-5.1)).thenReturn(2.6456584263993457);

        when(tf.sin(-5.15)).thenReturn(0.9057666414687044);
        when(tf.cos(-5.15)).thenReturn(0.4237768176794282);
        when(tf.tan(-5.15)).thenReturn(2.1373671321348304);
        when(tf.cot(-5.15)).thenReturn(0.46786534000884855);
        when(tf.csc(-5.15)).thenReturn(1.104037126360158);
        when(tf.sec(-5.15)).thenReturn(2.3597326665387905);

        when(tf.sin(-5.2)).thenReturn(0.8834546557201531);
        when(tf.cos(-5.2)).thenReturn(0.4685166713003771);
        when(tf.tan(-5.2)).thenReturn(1.8856418775197639);
        when(tf.cot(-5.2)).thenReturn(0.5303233938118341);
        when(tf.csc(-5.2)).thenReturn(1.1319200069015927);
        when(tf.sec(-5.2)).thenReturn(2.1343957670161036);
        when(tf.sin(-5.3)).thenReturn(0.8322674422239013);
        when(tf.cos(-5.3)).thenReturn(0.5543743361791608);
        when(tf.tan(-5.3)).thenReturn(1.50127339580693);
        when(tf.cot(-5.3)).thenReturn(0.6661011930225427);
        when(tf.csc(-5.3)).thenReturn(1.2015368489339204);
        when(tf.sec(-5.3)).thenReturn(1.8038353053861849);
        when(tf.sin(-5.4)).thenReturn(0.7727644875559871);
        when(tf.cos(-5.4)).thenReturn(0.6346928759426347);
        when(tf.tan(-5.4)).thenReturn(1.2175408246205552);
        when(tf.cot(-5.4)).thenReturn(0.8213276957769762);
        when(tf.csc(-5.4)).thenReturn(1.2940553248800133);
        when(tf.sec(-5.4)).thenReturn(1.575565187359032);
        when(tf.sin(-5.5)).thenReturn(0.7055403255703919);
        when(tf.cos(-5.5)).thenReturn(0.70866977429126);
        when(tf.tan(-5.5)).thenReturn(0.995584052213885);
        when(tf.cot(-5.5)).thenReturn(1.0044355348765333);
        when(tf.csc(-5.5)).thenReturn(1.4173534293614658);
        when(tf.sec(-5.5)).thenReturn(1.4110944706229345);
        when(tf.sin(-5.6)).thenReturn(0.6312666378723216);
        when(tf.cos(-5.6)).thenReturn(0.7755658785102496);
        when(tf.tan(-5.6)).thenReturn(0.8139432836897027);
        when(tf.cot(-5.6)).thenReturn(1.2285868315871835);
        when(tf.csc(-5.6)).thenReturn(1.5841166632383596);
        when(tf.sec(-5.6)).thenReturn(1.2893811186238053);

        when(tf.sin(-5.65)).thenReturn(0.5917155806310094);
        when(tf.cos(-5.65)).thenReturn(0.8061468052647157);
        when(tf.tan(-5.65)).thenReturn(0.7340047454963328);
        when(tf.cot(-5.65)).thenReturn(1.3623890119726703);
        when(tf.csc(-5.65)).thenReturn(1.69000113016053);
        when(tf.sec(-5.65)).thenReturn(1.2404688494319944);

        when(tf.sin(-5.7)).thenReturn(0.5506855425976376);
        when(tf.cos(-5.7)).thenReturn(0.8347127848391598);
        when(tf.tan(-5.7)).thenReturn(0.6597305715207762);
        when(tf.cot(-5.7)).thenReturn(1.5157702904306112);
        when(tf.csc(-5.7)).thenReturn(1.815918382899435);
        when(tf.sec(-5.7)).thenReturn(1.198016872585328);
        when(tf.sin(-5.8)).thenReturn(0.46460217941375737);
        when(tf.cos(-5.8)).thenReturn(0.8855195169413189);
        when(tf.tan(-5.8)).thenReturn(0.5246662219468002);
        when(tf.cot(-5.8)).thenReturn(1.9059736612916494);
        when(tf.csc(-5.8)).thenReturn(2.1523790552636157);
        when(tf.sec(-5.8)).thenReturn(1.1292805871225844);
        when(tf.sin(-6.0)).thenReturn(0.27941549819892586);
        when(tf.cos(-6.0)).thenReturn(0.960170286650366);
        when(tf.tan(-6.0)).thenReturn(0.29100619138474915);
        when(tf.cot(-6.0)).thenReturn(3.436353004180128);
        when(tf.csc(-6.0)).thenReturn(3.5788995472544056);
        when(tf.sec(-6.0)).thenReturn(1.0414819265951076);
        when(tf.sin(-6.2)).thenReturn(0.0830894028174964);
        when(tf.cos(-6.2)).thenReturn(0.9965420970232175);
        when(tf.tan(-6.2)).thenReturn(0.08337771486592861);
        when(tf.cot(-6.2)).thenReturn(11.993612461171432);
        when(tf.csc(-6.2)).thenReturn(12.035229115757067);
        when(tf.sec(-6.2)).thenReturn(1.003469901559715);

        IComplexFunctions complexFunctions = new ComplexFunctions(tf, lf);
        systemFunctions = new SystemFunctions(complexFunctions);
    }

    /*
     *  Test Positive Values
     */

    /**
     * x = (0.0; 0.55]
     */
    @Test
    public void testFirstPositiveRegionFromZeroX(){
        precisionAssertEquals(
                "Test [x = 0.02]: first positive region from zero X",
                -26465.8,
                systemFunctions.calculate(0.02)
        );
        precisionAssertEquals(
                "Test [x = 0.1]: first positive region from zero X",
                -675.99,
                systemFunctions.calculate(0.1)
        );
        precisionAssertEquals(
                "Test [x = 0.2]: first positive region from zero Xt",
                -60.0068,
                systemFunctions.calculate(0.2)
        );
        precisionAssertEquals(
                "Test [x = 0.3]: first positive region from zero Xt",
                -8.64993,
                systemFunctions.calculate(0.3)
        );
        precisionAssertEquals(
                "Test [x = 0.4]: first positive region from zero Xt",
                -0.999078,
                systemFunctions.calculate(0.4)
        );
        precisionAssertEquals(
                "Test [x = 0.5]: first positive region from zero Xt",
                0.487504,
                systemFunctions.calculate(0.5)
        );
        precisionAssertEquals(
                "Test [x = 0.55]: first positive region from zero Xt",
                0.714449,
                systemFunctions.calculate(0.55)
        );
    }

    /**
     * x = (0.55; 1.0)
     */
    @Test
    public void testSecondPositiveRegionToPuncturePoint() {
        precisionAssertEquals(
                "Test [x = 0.6]: second positive region to first puncture point",
                0.826229,
                systemFunctions.calculate(0.6)
        );
        precisionAssertEquals(
                "Test [x = 0.7]: second positive region to first puncture point",
                0.909484,
                systemFunctions.calculate(0.7)
        );
        precisionAssertEquals(
                "Test [x = 0.8]: second positive region to first puncture point",
                0.928675,
                systemFunctions.calculate(0.8)
        );
        precisionAssertEquals(
                "Test [x = 0.9]: second positive region to first puncture point",
                0.931799,
                systemFunctions.calculate(0.9)
        );
    }

    /**
     * x = 1.0
     */
    @Test
    public void testFirstPositivePuncturePoint() {
        assertTrue(
                "Test [x = 1.0]: first positive puncture point",
                Double.isNaN(systemFunctions.calculate(1d))
        );
    }

    /**
     * x = (1.0; 1.2]
     */
    @Test
    public void testThirdPositiveRegion(){
        precisionAssertEquals(
                "Test [x = 1.05]: third positive region",
                0.931952,
                systemFunctions.calculate(1.05)
        );
        precisionAssertEquals(
                "Test [x = 1.1]: third positive region",
                0.931852,
                systemFunctions.calculate(1.1)
        );
        precisionAssertEquals(
                "Test [x = 1.15]: third positive region",
                0.931464,
                systemFunctions.calculate(1.15)
        );
        precisionAssertEquals(
                "Test [x = 1.2]: third positive region",
                0.930531,
                systemFunctions.calculate(1.2)
        );
    }

    /**
     * x = (1.2; 1.75]
     */
    @Test
    public void testFourthPositiveRegion(){
        precisionAssertEquals(
                "Test [x = 1.3]: fourth positive region",
                0.92594,
                systemFunctions.calculate(1.3)
        );
        precisionAssertEquals(
                "Test [x = 1.5]: fourth positive region",
                0.900074,
                systemFunctions.calculate(1.5)
        );
        precisionAssertEquals(
                "Test [x = 1.75]: fourth positive region",
                0.836129,
                systemFunctions.calculate(1.75)
        );
    }

    /**
     * x = (1.75; e^(2^(2/3) (log(5)/(7 log(10)))^(1/3)))
     */
    @Test
    public void testFifthPositiveRegionToFirstExtreme(){
        precisionAssertEquals(
                "Test [x = 1.8]: fifth positive region",
                0.821522,
                systemFunctions.calculate(1.8)
        );
        precisionAssertEquals(
                "Test [x = 1.9]: fifth positive region",
                0.794358,
                systemFunctions.calculate(1.9)
        );
        precisionAssertEquals(
                "Test [x = 2.0]: fifth positive region",
                0.774356,
                systemFunctions.calculate(2.0)
        );
    }

    /**
     * x = e^(2^(2/3) (log(5)/(7 log(10)))^(1/3))
     */
    @Test
    public void testFirstPositiveExtreme(){
        double extremeX = 2.0884971449233825358269495952366013421428061969691576000370777169;
        double extremeY = 0.76756354102375411049030346684527510737400057387717261292998154511104;

        precisionAssertEquals(
                "Test [x = e^(2^(2/3) (log(5)/(7 log(10)))^(1/3))]: first positive extreme",
                extremeY,
                systemFunctions.calculate(extremeX)
        );
        assertTrue(
                "Test [x = 2.0]: extreme value Y less than left neighborhood value",
                systemFunctions.calculate(2.0) > extremeY
        );
        assertTrue(
                "Test [x = 2.1]: extreme value Y less than right neighborhood value",
                systemFunctions.calculate(2.1) > extremeY
        );
    }

    /**
     * x = ( e^(2^(2/3) (log(5)/(7 log(10)))^(1/3)); +inf)
     */
    @Test
    public void testSixthPositiveRegion() {
        precisionAssertEquals(
                "Test [x = 2.1]: sixth positive region",
                0.767694,
                systemFunctions.calculate(2.1)
        );
        precisionAssertEquals(
                "Test [x = 2.5]: fifth positive region",
                1.02447,
                systemFunctions.calculate(2.5)
        );
        precisionAssertEquals(
                "Test [x = 3.0]: fifth positive region",
                2.63606,
                systemFunctions.calculate(3.0)
        );
        precisionAssertEquals(
                "Test [x = 5.0]: fifth positive region",
                44.3698,
                systemFunctions.calculate(5.0)
        );
        precisionAssertEquals(
                "Test [x = 10.0]: fifth positive region",
                604.538,
                systemFunctions.calculate(10.0)
        );
        precisionAssertEquals(
                "Test [x = 20.0]: fifth positive region",
                3935.8,
                systemFunctions.calculate(20.0)
        );
        precisionAssertEquals(
                "Test [x = 100.0]: fifth positive region",
                81368.217,
                systemFunctions.calculate(100.0)
        );
    }

    /*
     *  Test Negative/Zero Values
     */

    /**
     * x = 0
     */
    @Test
    public void testZeroPuncturePoint(){
        assertTrue(
                "Test [x = 0.0]: zero value puncture point",
                Double.isNaN(systemFunctions.calculate(0))
        );
    }

    /**
     * x = (-1.2; 0.0)
     */
    @Test
    public void testFirstNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -0.4]: first negative region",
                50.2412,
                systemFunctions.calculate(-0.4)
        );
        precisionAssertEquals(
                "Test [x = 0.7]: first negative region",
                10.964,
                systemFunctions.calculate(-0.7)
        );
        precisionAssertEquals(
                "Test [x = -1.15]: first negative region",
                3.65397,
                systemFunctions.calculate(-1.15)
        );
    }

    /**
     * x = -1.2
     */
    @Test
    public void testFirstNegativeExtremePoint() {
        double extremeY = 3.60465;
        precisionAssertEquals(
                "Test [x = -1.2]: first negative extreme point",
                extremeY,
                systemFunctions.calculate(-1.2)
        );
        assertTrue(
                "Test [x = -1.2]: extreme value Y less than left neighborhood",
                systemFunctions.calculate(-1.25) > extremeY
        );
        assertTrue(
                "Test [x = -1.2]: extreme value Y high less right neighborhood",
                systemFunctions.calculate(-1.15) > extremeY
        );
    }

    /**
     * x = (-pi/2; -1.2)
     */
    @Test
    public void testSecondNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -1.3]: second negative region",
                3.97437,
                systemFunctions.calculate(-1.3)
        );
        precisionAssertEquals(
                "Test [x = -1.4]: second negative region",
                5.61428,
                systemFunctions.calculate(-1.4)
        );
        precisionAssertEquals(
                "Test [x = -1.5]: second negative region",
                13.4263,
                systemFunctions.calculate(-1.5)
        );
    }

    /**
     * x = -pi/2
     */
    @Test
    public void testFirstNegativePuncturePoint(){
        var result = systemFunctions.calculate(-Math.PI / 2);
        assertTrue(
                "Test [x = -pi/2]: puncture point",
                Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
        );
    }

    /**
     * x = (-1.95; -pi/2)
     */
    @Test
    public void testThirdNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -1.7]: third negative region",
                -9.26823,
                systemFunctions.calculate(-1.7)
        );
        precisionAssertEquals(
                "Test [x = -1.8]: third negative region",
                -6.30266,
                systemFunctions.calculate(-1.8)
        );
        precisionAssertEquals(
                "Test [x = -1.9]: third negative region",
                -5.40983,
                systemFunctions.calculate(-1.9)
        );
    }

    /**
     * x = -1.95
     */
    @Test
    public void testSecondNegativeExtremePoint() {
        double extremeY = -5.23951;
        precisionAssertEquals(
                "Test [x = -1.95]: second negative extreme point",
                extremeY,
                systemFunctions.calculate(-1.95)
        );
        assertTrue(
                "Test [x = -1.9]: extreme value Y greater than left neighborhood",
                systemFunctions.calculate(-1.9) < extremeY
        );
        assertTrue(
                "Test [x = -2.1]: extreme value Y greater right neighborhood",
                systemFunctions.calculate(-2.1) < extremeY
        );
    }

    /**
     * x = (-pi; -1.95)
     */
    @Test
    public void testFourthNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -2.2]: fourth negative region",
                -5.61752,
                systemFunctions.calculate(-2.2)
        );
        precisionAssertEquals(
                "Test [x = -2.5]: fourth negative region",
                -8.44473,
                systemFunctions.calculate(-2.5)
        );
        precisionAssertEquals(
                "Test [x = -2.8]: fourth negative region",
                -21.5672,
                systemFunctions.calculate(-2.8)
        );
        precisionAssertEquals(
                "Test [x = -3.1]: fourth negative region",
                -1171.27,
                systemFunctions.calculate(-3.1)
        );
    }

    /**
     * x = -pi
     */
    @Test
    public void testSecondNegativePuncturePoint() {
        double result = systemFunctions.calculate(-Math.PI);
        assertTrue(
                "Test [x = -pi]: puncture point",
                Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
        );
    }

    /**
     * x = (-4.25; -pi)
     */
    @Test
    public void testFifthNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -3.2]: fifth negative region",
                -580.903,
                systemFunctions.calculate(-3.2)
        );
        precisionAssertEquals(
                "Test [x = -3.5]: fifth negative region",
                -17.4998,
                systemFunctions.calculate(-3.5)
        );
        precisionAssertEquals(
                "Test [x = -3.8]: fifth negative region",
                -7.27089,
                systemFunctions.calculate(-3.8)
        );
        precisionAssertEquals(
                "Test [x = -4.2]: fifth negative region",
                -5.05901,
                systemFunctions.calculate(-4.2)
        );
    }

    /**
     * x = -4.25
     */
    @Test
    public void testThirdNegativeExtremePoint() {
        double extremeY = -5.04151;
        precisionAssertEquals(
                "Test [x = -4.25]: third negative extreme point",
                extremeY,
                systemFunctions.calculate(-4.25)
        );
        assertTrue(
                "Test [x = -4.2]: extreme value Y greater than left neighborhood",
                systemFunctions.calculate(-4.2) < extremeY
        );
        assertTrue(
                "Test [x = -4.3]: extreme value Y greater right neighborhood",
                systemFunctions.calculate(-4.3) < extremeY
        );
    }

    /**
     * x = (-3pi/2; -4.25)
     */
    @Test
    public void testSixthNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -4.3]: sixth negative region",
                -5.08678,
                systemFunctions.calculate(-4.3)
        );
        precisionAssertEquals(
                "Test [x = -4.4]: sixth negative region",
                -5.45166,
                systemFunctions.calculate(-4.4)
        );
        precisionAssertEquals(
                "Test [x = -4.5]: sixth negative region",
                -6.5621,
                systemFunctions.calculate(-4.5)
        );
        precisionAssertEquals(
                "Test [x = -4.6]: sixth negative region",
                -10.3553,
                systemFunctions.calculate(-4.6)
        );
    }

    /**
     * x = -3pi/2
     */
    @Test
    public void testThirdNegativePuncturePoint(){
        double result = systemFunctions.calculate(-3 * Math.PI / 2);
        assertTrue(
                "Test [x = -3pi/2]: puncture point",
                Double.isNaN(result) || Math.abs(result) > PuncturePointLimit
        );
    }

    /**
     * x = (-5.15; -3pi/2)
     */
    @Test
    public void testSeventhNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -4.8]: seventh negative region",
                10.7877,
                systemFunctions.calculate(-4.8)
        );
        precisionAssertEquals(
                "Test [x = -4.9]: seventh negative region",
                5.15571,
                systemFunctions.calculate(-4.9)
        );
        precisionAssertEquals(
                "Test [x = -5.0]: seventh negative region",
                3.78871,
                systemFunctions.calculate(-5.0)
        );
        precisionAssertEquals(
                "Test [x = -5.1]: seventh negative region",
                3.41948,
                systemFunctions.calculate(-5.1)
        );
    }

    /**
     * x = -5.15
     */
    @Test
    public void testFourthNegativeExtremePoint() {
        double extremeY = 3.40621;
        precisionAssertEquals(
                "Test [x = -5.15]: fourth negative extreme point",
                extremeY,
                systemFunctions.calculate(-5.15)
        );
        assertTrue(
                "Test [x = -5.1]: extreme value Y less than left neighborhood",
                systemFunctions.calculate(-5.1) > extremeY
        );
        assertTrue(
                "Test [x = -5.2]: extreme value Y less right neighborhood",
                systemFunctions.calculate(-5.2) > extremeY
        );
    }

    /**
     * x = (-5.7; -5.15)
     */
    @Test
    public void testEightNegativeRegionToExtremePoint(){
        precisionAssertEquals(
                "Test [x = -5.3]: eight negative region",
                3.74355,
                systemFunctions.calculate(-5.3)
        );
        precisionAssertEquals(
                "Test [x = -5.4]: eight negative region",
                4.16767,
                systemFunctions.calculate(-5.4)
        );
        precisionAssertEquals(
                "Test [x = -5.5]: eight negative region",
                4.66807,
                systemFunctions.calculate(-5.5)
        );
        precisionAssertEquals(
                "Test [x = -5.6]: eight negative region",
                5.12033,
                systemFunctions.calculate(-5.6)
        );
    }

    /**
     * x = -5.65
     */
    @Test
    public void tesFifthNegativeExtremePoint() {
        double extremeY = 5.24277;
        precisionAssertEquals(
                "Test [x = -5.65]: fourth negative extreme point",
                extremeY,
                systemFunctions.calculate(-5.65)
        );
        assertTrue(
                "Test [x = -5.6]: extreme value Y greater than left neighborhood",
                systemFunctions.calculate(-5.6) < extremeY
        );
        assertTrue(
                "Test [x = -5.7]: extreme value Y greater right neighborhood",
                systemFunctions.calculate(-5.7) < extremeY
        );
    }

    /**
     * x = (-2pi; -5.65)
     */
    @Test
    public void testNineNegativeRegionToPuncturePoint(){
        precisionAssertEquals(
                "Test [x = -5.8]: nine negative region",
                3.89952,
                systemFunctions.calculate(-5.8)
        );
        precisionAssertEquals(
                "Test [x = -6.0]: nine negative region",
                -29.835,
                systemFunctions.calculate(-6.0)
        );
        precisionAssertEquals(
                "Test [x = -6.2]: nine negative region",
                -2866.63,
                systemFunctions.calculate(-6.2)
        );
    }
}
