
// rumor_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  1.400000
 // --table_div  3.393005
 // --table_op  1.000000

struct tablerumor { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tablerumor_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tablerumor&() const { return *(tablerumor*)this; }
};

 static tablerumor_imp<200> rumor_table = {
	0,0.833333,142.143,200, {
	0.000000000000,0.001179247307,0.005700404200,0.013696114078,0.023372061838,
	0.033432794676,0.043461811993,0.053388498434,0.063206993536,0.072917985483,
	0.082522533444,0.092021701974,0.101416548612,0.110708139580,0.119897750725,
	0.128986887338,0.137976888372,0.146868847166,0.155663806805,0.164362801522,
	0.172966854232,0.181476976838,0.189894170368,0.198219425108,0.206453720733,
	0.214598026432,0.222653301025,0.230620493087,0.238500541057,0.246294373355,
	0.254002908490,0.261627055172,0.269167712416,0.276625769647,0.284002106808,
	0.291297594461,0.298513093886,0.305649457186,0.312707527379,0.319688138504,
	0.326592115711,0.333420275357,0.340173425105,0.346852364012,0.353457882624,
	0.359990763066,0.366451779133,0.372841696377,0.379161272199,0.385411255930,
	0.391592388924,0.397705404640,0.403751028723,0.409729979096,0.415642966031,
	0.421490692243,0.427273852959,0.432993136006,0.438649221887,0.444242783860,
	0.449774488011,0.455244993338,0.460654951821,0.466005008498,0.471295801539,
	0.476527962321,0.481702115497,0.486818879071,0.491878864466,0.496882676597,
	0.501830913938,0.506724168591,0.511563026356,0.516348066795,0.521079863300,
	0.525758983159,0.530385987621,0.534961431958,0.539485865535,0.543959831863,
	0.548383868671,0.552758507962,0.557084276074,0.561361693746,0.565591276168,
	0.569773533050,0.573908968673,0.577998081951,0.582041366486,0.586039310626,
	0.589992397521,0.593901105176,0.597765906508,0.601587269401,0.605365656755,
	0.609101526546,0.612795331873,0.616447521011,0.620058537463,0.623628820013,
	0.627158802772,0.630648915230,0.634099582305,0.637511224392,0.640884257411,
	0.644219092854,0.647516137833,0.650775795125,0.653998463223,0.657184536373,
	0.660334404627,0.663448453885,0.666527065939,0.669570618516,0.672579485321,
	0.675554036085,0.678494636598,0.681401648760,0.684275430616,0.687116336403,
	0.689924716583,0.692700917890,0.695445283366,0.698158152402,0.700839860776,
	0.703490740691,0.706111120814,0.708701326313,0.711261678897,0.713792496847,
	0.716294095057,0.718766785071,0.721210875114,0.723626670131,0.726014471821,
	0.728374578671,0.730707285991,0.733012885948,0.735291667597,0.737543916918,
	0.739769916846,0.741969947304,0.744144285236,0.746293204636,0.748416976584,
	0.750515869273,0.752590148041,0.754640075401,0.756665911073,0.758667912011,
	0.760646332435,0.762601423857,0.764533435114,0.766442612393,0.768329199259,
	0.770193436687,0.772035563085,0.773855814323,0.775654423761,0.777431622274,
	0.779187638282,0.780922697769,0.782637024317,0.784330839128,0.786004361046,
	0.787657806589,0.789291389968,0.790905323116,0.792499815706,0.794075075183,
	0.795631306783,0.797168713555,0.798687496389,0.800187854035,0.801669983128,
	0.803134078210,0.804580331752,0.806008934176,0.807420073876,0.808813937243,
	0.810190708681,0.811550570633,0.812893703599,0.814220286159,0.815530494989,
	0.816824504887,0.818102488790,0.819364617792,0.820611061169,0.821841986392,
	0.823057559150,0.824257943370,0.825443301233,0.826613793191,0.827769577993,
	0.828910812693,0.830037652677,0.831150251674,0.832248761780,0.833333333468
	}
};

double always_inline rumorclip(double x) {
    double f = fabs(x);
    f = f * rumor_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = rumor_table.data[0];
    } else if (i >= rumor_table.size-1) {
        f = rumor_table.data[rumor_table.size-1];
    } else {
    f -= i;
    f = rumor_table.data[i]*(1-f) + rumor_table.data[i+1]*f;
    }
    return copysign(f, x);
}

