#ifndef TRIGONOMETRIC_H
#define TRIGONOMETRIC_H

float sin_value[360] = {
    0.0, 0.01745240643728351, 0.03489949670250097, 0.05233595624294383, 0.0697564737441253, 0.08715574274765817, 0.10452846326765346, 0.12186934340514748, 0.13917310096006544, 0.15643446504023087, 0.17364817766693033, 0.1908089953765448, 0.20791169081775931, 0.22495105434386498, 0.24192189559966773, 0.25881904510252074, 0.27563735581699916, 0.2923717047227367, 0.3090169943749474, 0.3255681544571567, 0.3420201433256687, 0.35836794954530027, 0.374606593415912, 0.3907311284892737, 0.40673664307580015, 0.42261826174069944, 0.4383711467890774, 0.4539904997395468, 0.4694715627858908, 0.48480962024633706, 0.49999999999999994, 0.5150380749100542, 0.5299192642332049, 0.544639035015027, 0.5591929034707468, 0.573576436351046, 0.5877852522924731, 0.6018150231520483, 0.6156614753256583, 0.6293203910498375, 0.6427876096865393, 0.6560590289905073, 0.6691306063588582, 0.6819983600624985, 0.6946583704589973, 0.7071067811865475, 0.7193398003386511, 0.7313537016191705, 0.7431448254773942, 0.7547095802227719, 0.766044443118978, 0.7771459614569708, 0.7880107536067219, 0.7986355100472928, 0.8090169943749475, 0.8191520442889918, 0.8290375725550417, 0.8386705679454239, 0.848048096156426, 0.8571673007021122, 0.8660254037844386, 0.8746197071393957, 0.8829475928589269, 0.8910065241883679, 0.8987940462991669, 0.9063077870366499, 0.9135454576426008, 0.9205048534524404, 0.9271838545667873, 0.9335804264972017, 0.9396926207859083, 0.9455185755993167, 0.9510565162951535, 0.9563047559630354, 0.9612616959383189, 0.9659258262890683, 0.9702957262759965, 0.9743700647852352, 0.9781476007338057, 0.981627183447664, 0.984807753012208, 0.9876883405951378, 0.9902680687415704, 0.992546151641322, 0.9945218953682733, 0.9961946980917455, 0.9975640502598242, 0.9986295347545738, 0.9993908270190958, 0.9998476951563913, 1.0, 0.9998476951563913, 0.9993908270190958, 0.9986295347545738, 0.9975640502598242, 0.9961946980917455, 0.9945218953682734, 0.9925461516413221, 0.9902680687415704, 0.9876883405951377, 0.984807753012208, 0.981627183447664, 0.9781476007338057, 0.9743700647852352, 0.9702957262759965, 0.9659258262890683, 0.9612616959383189, 0.9563047559630355, 0.9510565162951536, 0.9455185755993168, 0.9396926207859084, 0.9335804264972017, 0.9271838545667874, 0.9205048534524404, 0.913545457642601, 0.90630778703665, 0.8987940462991669, 0.8910065241883679, 0.8829475928589271, 0.8746197071393959, 0.8660254037844387, 0.8571673007021123, 0.8480480961564261, 0.838670567945424, 0.8290375725550417, 0.819152044288992, 0.8090169943749475, 0.7986355100472927, 0.788010753606722, 0.777145961456971, 0.766044443118978, 0.7547095802227721, 0.7431448254773945, 0.7313537016191706, 0.7193398003386511, 0.7071067811865476, 0.6946583704589975, 0.6819983600624986, 0.669130606358858, 0.6560590289905073, 0.6427876096865395, 0.6293203910498374, 0.6156614753256584, 0.6018150231520486, 0.5877852522924732, 0.5735764363510459, 0.5591929034707469, 0.5446390350150273, 0.529919264233205, 0.5150380749100544, 0.49999999999999994, 0.48480962024633717, 0.4694715627858907, 0.45399049973954686, 0.4383711467890777, 0.4226182617406995, 0.40673664307580004, 0.39073112848927377, 0.37460659341591224, 0.35836794954530066, 0.3420201433256689, 0.3255681544571566, 0.3090169943749475, 0.29237170472273705, 0.2756373558169992, 0.258819045102521, 0.24192189559966773, 0.2249510543438652, 0.20791169081775931, 0.19080899537654497, 0.17364817766693072, 0.15643446504023098, 0.13917310096006533, 0.12186934340514755, 0.10452846326765373, 0.0871557427476582, 0.06975647374412552, 0.05233595624294425, 0.03489949670250114, 0.01745240643728344, 1.2246467991473532e-16, -0.017452406437283192, -0.0348994967025009, -0.052335956242943564, -0.06975647374412483, -0.08715574274765794, -0.1045284632676535, -0.12186934340514775, -0.13917310096006552, -0.15643446504023073, -0.17364817766693047, -0.19080899537654472, -0.20791169081775907, -0.22495105434386498, -0.2419218955996675, -0.25881904510252035, -0.2756373558169986, -0.29237170472273677, -0.30901699437494773, -0.32556815445715676, -0.34202014332566866, -0.35836794954530043, -0.374606593415912, -0.39073112848927355, -0.4067366430757998, -0.4226182617406993, -0.43837114678907707, -0.45399049973954625, -0.4694715627858905, -0.48480962024633734, -0.5000000000000001, -0.5150380749100542, -0.5299192642332048, -0.5446390350150271, -0.5591929034707467, -0.5735764363510458, -0.587785252292473, -0.601815023152048, -0.6156614753256578, -0.6293203910498373, -0.6427876096865393, -0.6560590289905074, -0.6691306063588582, -0.6819983600624984, -0.6946583704589974, -0.7071067811865475, -0.7193398003386509, -0.7313537016191703, -0.743144825477394, -0.7547095802227717, -0.7660444431189779, -0.7771459614569711, -0.7880107536067221, -0.7986355100472928, -0.8090169943749473, -0.8191520442889916, -0.8290375725550414, -0.8386705679454242, -0.848048096156426, -0.8571673007021121, -0.8660254037844384, -0.8746197071393955, -0.882947592858927, -0.8910065241883678, -0.8987940462991668, -0.90630778703665, -0.913545457642601, -0.9205048534524403, -0.9271838545667873, -0.9335804264972015, -0.9396926207859082, -0.9455185755993168, -0.9510565162951535, -0.9563047559630353, -0.961261695938319, -0.9659258262890683, -0.9702957262759965, -0.9743700647852351, -0.9781476007338056, -0.981627183447664, -0.984807753012208, -0.9876883405951377, -0.9902680687415703, -0.992546151641322, -0.9945218953682733, -0.9961946980917455, -0.9975640502598242, -0.9986295347545739, -0.9993908270190958, -0.9998476951563913, -1.0, -0.9998476951563913, -0.9993908270190958, -0.9986295347545739, -0.9975640502598243, -0.9961946980917455, -0.9945218953682733, -0.992546151641322, -0.9902680687415704, -0.9876883405951378, -0.9848077530122081, -0.9816271834476641, -0.9781476007338056, -0.9743700647852352, -0.9702957262759966, -0.9659258262890684, -0.961261695938319, -0.9563047559630354, -0.9510565162951536, -0.945518575599317, -0.9396926207859083, -0.9335804264972017, -0.9271838545667874, -0.9205048534524405, -0.9135454576426011, -0.9063077870366503, -0.898794046299167, -0.8910065241883679, -0.8829475928589271, -0.8746197071393956, -0.8660254037844386, -0.8571673007021123, -0.8480480961564262, -0.8386705679454243, -0.8290375725550416, -0.8191520442889918, -0.8090169943749476, -0.7986355100472932, -0.7880107536067223, -0.7771459614569713, -0.7660444431189781, -0.7547095802227722, -0.743144825477394, -0.7313537016191703, -0.7193398003386512, -0.7071067811865477, -0.6946583704589976, -0.6819983600624989, -0.6691306063588588, -0.6560590289905074, -0.6427876096865396, -0.6293203910498372, -0.6156614753256582, -0.6018150231520483, -0.5877852522924734, -0.5735764363510465, -0.5591929034707473, -0.544639035015027, -0.529919264233205, -0.5150380749100545, -0.5000000000000004, -0.48480962024633767, -0.4694715627858908, -0.45399049973954697, -0.4383711467890778, -0.4226182617406992, -0.40673664307580015, -0.3907311284892739, -0.37460659341591235, -0.35836794954530077, -0.34202014332566943, -0.3255681544571567, -0.3090169943749477, -0.29237170472273716, -0.27563735581699894, -0.2588190451025207, -0.24192189559966787, -0.22495105434386534, -0.20791169081775987, -0.19080899537654467, -0.1736481776669304, -0.15643446504023112, -0.13917310096006588, -0.12186934340514811, -0.1045284632676543, -0.08715574274765832, -0.06975647374412564, -0.05233595624294348, -0.034899496702500823, -0.01745240643728356};

float cos_value[360] = {
    1.0, 0.9998476951563913, 0.9993908270190958, 0.9986295347545738, 0.9975640502598242, 0.9961946980917455, 0.9945218953682733, 0.992546151641322, 0.9902680687415704, 0.9876883405951378, 0.984807753012208, 0.981627183447664, 0.9781476007338057, 0.9743700647852352, 0.9702957262759965, 0.9659258262890683, 0.9612616959383189, 0.9563047559630355, 0.9510565162951535, 0.9455185755993168, 0.9396926207859084, 0.9335804264972017, 0.9271838545667874, 0.9205048534524404, 0.9135454576426009, 0.9063077870366499, 0.898794046299167, 0.8910065241883679, 0.882947592858927, 0.8746197071393957, 0.8660254037844387, 0.8571673007021123, 0.848048096156426, 0.838670567945424, 0.8290375725550417, 0.8191520442889918, 0.8090169943749475, 0.7986355100472928, 0.7880107536067219, 0.7771459614569708, 0.766044443118978, 0.754709580222772, 0.7431448254773942, 0.7313537016191705, 0.7193398003386512, 0.7071067811865476, 0.6946583704589974, 0.6819983600624985, 0.6691306063588582, 0.6560590289905074, 0.6427876096865394, 0.6293203910498375, 0.6156614753256584, 0.6018150231520483, 0.5877852522924731, 0.573576436351046, 0.5591929034707468, 0.5446390350150271, 0.5299192642332049, 0.5150380749100543, 0.5000000000000001, 0.4848096202463371, 0.46947156278589086, 0.45399049973954686, 0.43837114678907746, 0.42261826174069944, 0.4067366430758004, 0.3907311284892737, 0.3746065934159122, 0.35836794954530016, 0.3420201433256688, 0.32556815445715676, 0.30901699437494745, 0.29237170472273677, 0.27563735581699916, 0.25881904510252074, 0.24192189559966767, 0.22495105434386514, 0.20791169081775923, 0.19080899537654492, 0.17364817766693041, 0.15643446504023092, 0.13917310096006547, 0.12186934340514749, 0.10452846326765346, 0.08715574274765836, 0.06975647374412523, 0.052335956242943966, 0.03489949670250108, 0.0174524064372836, 6.123233995736766e-17, -0.017452406437283477, -0.03489949670250073, -0.05233595624294384, -0.06975647374412533, -0.08715574274765824, -0.10452846326765333, -0.12186934340514737, -0.13917310096006513, -0.15643446504023104, -0.1736481776669303, -0.1908089953765448, -0.20791169081775912, -0.2249510543438648, -0.24192189559966756, -0.25881904510252085, -0.27563735581699905, -0.29237170472273666, -0.30901699437494734, -0.3255681544571564, -0.3420201433256687, -0.35836794954530027, -0.37460659341591207, -0.3907311284892736, -0.40673664307580004, -0.42261826174069933, -0.4383711467890775, -0.45399049973954675, -0.46947156278589053, -0.484809620246337, -0.49999999999999983, -0.5150380749100543, -0.5299192642332048, -0.5446390350150272, -0.5591929034707467, -0.5735764363510458, -0.587785252292473, -0.6018150231520484, -0.6156614753256583, -0.6293203910498373, -0.6427876096865394, -0.6560590289905072, -0.6691306063588579, -0.6819983600624984, -0.6946583704589974, -0.7071067811865475, -0.719339800338651, -0.7313537016191705, -0.7431448254773944, -0.754709580222772, -0.7660444431189779, -0.7771459614569709, -0.7880107536067219, -0.7986355100472926, -0.8090169943749473, -0.8191520442889919, -0.8290375725550416, -0.8386705679454239, -0.848048096156426, -0.8571673007021122, -0.8660254037844387, -0.8746197071393957, -0.882947592858927, -0.8910065241883678, -0.8987940462991668, -0.9063077870366499, -0.913545457642601, -0.9205048534524404, -0.9271838545667873, -0.9335804264972016, -0.9396926207859083, -0.9455185755993168, -0.9510565162951535, -0.9563047559630354, -0.9612616959383189, -0.9659258262890682, -0.9702957262759965, -0.9743700647852351, -0.9781476007338057, -0.9816271834476639, -0.984807753012208, -0.9876883405951377, -0.9902680687415704, -0.992546151641322, -0.9945218953682733, -0.9961946980917455, -0.9975640502598242, -0.9986295347545738, -0.9993908270190958, -0.9998476951563913, -1.0, -0.9998476951563913, -0.9993908270190958, -0.9986295347545738, -0.9975640502598243, -0.9961946980917455, -0.9945218953682733, -0.992546151641322, -0.9902680687415703, -0.9876883405951378, -0.984807753012208, -0.981627183447664, -0.9781476007338057, -0.9743700647852352, -0.9702957262759965, -0.9659258262890684, -0.961261695938319, -0.9563047559630354, -0.9510565162951535, -0.9455185755993167, -0.9396926207859084, -0.9335804264972016, -0.9271838545667874, -0.9205048534524404, -0.9135454576426011, -0.90630778703665, -0.8987940462991671, -0.8910065241883681, -0.8829475928589271, -0.8746197071393956, -0.8660254037844386, -0.8571673007021123, -0.8480480961564261, -0.838670567945424, -0.8290375725550418, -0.819152044288992, -0.8090169943749475, -0.798635510047293, -0.7880107536067222, -0.7771459614569711, -0.766044443118978, -0.7547095802227719, -0.7431448254773942, -0.7313537016191706, -0.7193398003386511, -0.7071067811865477, -0.6946583704589975, -0.6819983600624986, -0.6691306063588585, -0.6560590289905076, -0.6427876096865395, -0.6293203910498371, -0.6156614753256581, -0.6018150231520483, -0.5877852522924732, -0.5735764363510464, -0.5591929034707472, -0.544639035015027, -0.529919264233205, -0.5150380749100544, -0.5000000000000004, -0.4848096202463376, -0.46947156278589075, -0.45399049973954697, -0.43837114678907774, -0.42261826174069916, -0.4067366430758001, -0.3907311284892738, -0.3746065934159123, -0.3583679495453007, -0.3420201433256694, -0.32556815445715664, -0.30901699437494756, -0.2923717047227371, -0.2756373558169989, -0.25881904510252063, -0.24192189559966779, -0.22495105434386525, -0.2079116908177598, -0.1908089953765446, -0.17364817766693033, -0.15643446504023104, -0.13917310096006583, -0.12186934340514805, -0.10452846326765423, -0.08715574274765825, -0.06975647374412558, -0.052335956242943425, -0.03489949670250076, -0.017452406437283498, -1.8369701987210297e-16, 0.01745240643728313, 0.03489949670250039, 0.05233595624294306, 0.06975647374412522, 0.08715574274765789, 0.10452846326765387, 0.12186934340514768, 0.13917310096006547, 0.15643446504023067, 0.17364817766692997, 0.19080899537654425, 0.20791169081775945, 0.22495105434386492, 0.24192189559966745, 0.2588190451025203, 0.2756373558169985, 0.2923717047227367, 0.30901699437494723, 0.3255681544571563, 0.342020143325669, 0.3583679495453004, 0.37460659341591196, 0.3907311284892735, 0.40673664307579976, 0.42261826174069883, 0.4383711467890774, 0.45399049973954664, 0.4694715627858904, 0.4848096202463373, 0.5000000000000001, 0.5150380749100542, 0.5299192642332047, 0.5446390350150266, 0.559192903470747, 0.573576436351046, 0.5877852522924729, 0.6018150231520479, 0.6156614753256578, 0.6293203910498368, 0.6427876096865393, 0.656059028990507, 0.6691306063588585, 0.6819983600624987, 0.6946583704589973, 0.7071067811865474, 0.7193398003386509, 0.73135370161917, 0.7431448254773937, 0.7547095802227719, 0.7660444431189778, 0.7771459614569711, 0.7880107536067221, 0.7986355100472928, 0.8090169943749473, 0.8191520442889916, 0.8290375725550413, 0.838670567945424, 0.8480480961564258, 0.8571673007021121, 0.8660254037844384, 0.8746197071393954, 0.882947592858927, 0.8910065241883678, 0.8987940462991668, 0.90630778703665, 0.9135454576426009, 0.9205048534524403, 0.9271838545667873, 0.9335804264972015, 0.9396926207859081, 0.9455185755993168, 0.9510565162951535, 0.9563047559630353, 0.9612616959383189, 0.9659258262890683, 0.9702957262759965, 0.9743700647852351, 0.9781476007338056, 0.981627183447664, 0.984807753012208, 0.9876883405951377, 0.9902680687415703, 0.992546151641322, 0.9945218953682733, 0.9961946980917455, 0.9975640502598242, 0.9986295347545739, 0.9993908270190958, 0.9998476951563913};

float cot_value[360] = {
    -999, 57.28996163075943, 28.636253282915604, 19.08113668772821, 14.300666256711928, 11.430052302761345, 9.514364454222585, 8.144346427974593, 7.11536972238421, 6.313751514675044, 5.671281819617709, 5.144554015970311, 4.704630109478455, 4.3314758742841555, 4.010780933535845, 3.7320508075688776, 3.4874144438409087, 3.2708526184841404, 3.077683537175254, 2.904210877675823, 2.7474774194546225, 2.605089064693802, 2.475086853416296, 2.355852365823753, 2.2460367739042164, 2.1445069205095586, 2.0503038415792965, 1.9626105055051506, 1.880726465346332, 1.8040477552714238, 1.7320508075688776, 1.6642794823505183, 1.6003345290410504, 1.5398649638145832, 1.48256096851274, 1.4281480067421146, 1.3763819204711736, 1.32704482162041, 1.2799416321930792, 1.2348971565350515, 1.1917535925942102, 1.1503684072210099, 1.110612514829193, 1.0723687100246828, 1.0355303137905696, 1.0000000000000002, 0.9656887748070742, 0.9325150861376617, 0.9004040442978402, 0.8692867378162269, 0.8390996311772801, 0.8097840331950075, 0.7812856265067174, 0.7535540501027943, 0.7265425280053611, 0.7002075382097099, 0.6745085168424269, 0.6494075931975107, 0.6248693519093275, 0.6008606190275607, 0.577350269189626, 0.5543090514527691, 0.5317094316614789, 0.5095254494944289, 0.4877325885658614, 0.4663076581549986, 0.4452286853085361, 0.4244748162096049, 0.40402622583515674, 0.3838640350354159, 0.3639702342662025, 0.3443276132896654, 0.32491969623290634, 0.3057306814586604, 0.2867453857588079, 0.2679491924311227, 0.24932800284318085, 0.23086819112556303, 0.21255656167002226, 0.1943803091377186, 0.17632698070846503, 0.15838444032453633, 0.1405408347023917, 0.1227845609029046, 0.10510423526567644, 0.08748866352592395, 0.06992681194351057, 0.05240777928304134, 0.03492076949174784, 0.017455064928217447, 6.123233995736766e-17, -0.017455064928217547, -0.034920769491747494, -0.05240777928304099, -0.06992681194351046, -0.08748866352592406, -0.10510423526567632, -0.12278456090290447, -0.14054083470239134, -0.15838444032453647, -0.17632698070846492, -0.19438030913771848, -0.2125565616700219, -0.23086819112556292, -0.24932800284318074, -0.26794919243112275, -0.2867453857588078, -0.3057306814586603, -0.32491969623290623, -0.34432761328966494, -0.36397023426620234, -0.38386403503541583, -0.40402622583515685, -0.42447481620960453, -0.445228685308536, -0.4663076581549984, -0.4877325885658616, -0.5095254494944288, -0.5317094316614783, -0.5543090514527689, -0.5773502691896254, -0.6008606190275603, -0.6248693519093272, -0.6494075931975105, -0.6745085168424263, -0.7002075382097093, -0.7265425280053608, -0.7535540501027943, -0.7812856265067173, -0.8097840331950067, -0.8390996311772798, -0.8692867378162271, -0.90040404429784, -0.9325150861376613, -0.9656887748070734, -0.9999999999999998, -1.03553031379057, -1.0723687100246826, -1.1106125148291923, -1.1503684072210096, -1.1917535925942095, -1.2348971565350506, -1.2799416321930783, -1.3270448216204105, -1.3763819204711731, -1.4281480067421135, -1.48256096851274, -1.5398649638145838, -1.6003345290410504, -1.6642794823505171, -1.7320508075688776, -1.8040477552714234, -1.8807264653463303, -1.9626105055051501, -2.050303841579297, -2.144506920509558, -2.2460367739042146, -2.35585236582375, -2.475086853416294, -2.605089064693802, -2.7474774194546208, -2.90421087767582, -3.0776835371752522, -3.2708526184841373, -3.487414443840902, -3.7320508075688736, -4.010780933535845, -4.33147587428416, -4.7046301094784555, -5.144554015970306, -5.671281819617713, -6.3137515146750385, -7.115369722384193, -8.14434642797459, -9.51436445422256, -11.430052302761283, -14.300666256711882, -19.08113668772822, -28.636253282915824, -57.28996163075968, -8165619676597685.0, 57.28996163076047, 28.636253282915668, 19.08113668772831, 14.300666256712024, 11.430052302761373, 9.514364454222623, 8.144346427974575, 7.115369722384204, 6.313751514675048, 5.671281819617705, 5.144554015970312, 4.70463010947846, 4.331475874284156, 4.010780933535848, 3.7320508075688834, 3.487414443840911, 3.2708526184841453, 3.07768353717525, 2.9042108776758213, 2.747477419454623, 2.6050890646938, 2.475086853416296, 2.3558523658237545, 2.2460367739042186, 2.1445069205095595, 2.0503038415792982, 1.9626105055051533, 1.8807264653463316, 1.8040477552714245, 1.7320508075688767, 1.6642794823505183, 1.6003345290410511, 1.5398649638145832, 1.482560968512741, 1.4281480067421155, 1.3763819204711738, 1.327044821620411, 1.27994163219308, 1.2348971565350508, 1.1917535925942102, 1.1503684072210092, 1.110612514829193, 1.072368710024683, 1.0355303137905694, 1.0000000000000004, 0.9656887748070748, 0.9325150861376628, 0.9004040442978406, 0.8692867378162276, 0.8390996311772805, 0.8097840331950065, 0.7812856265067173, 0.7535540501027942, 0.7265425280053611, 0.7002075382097103, 0.6745085168424275, 0.6494075931975105, 0.6248693519093277, 0.6008606190275608, 0.5773502691896265, 0.5543090514527687, 0.5317094316614787, 0.509525449494429, 0.4877325885658619, 0.46630765815499925, 0.445228685308536, 0.42447481620960487, 0.4040262258351571, 0.38386403503541633, 0.363970234266203, 0.3443276132896652, 0.3249196962329065, 0.3057306814586607, 0.2867453857588076, 0.26794919243112253, 0.2493280028431808, 0.23086819112556345, 0.21255656167002263, 0.19438030913771917, 0.17632698070846495, 0.1583844403245365, 0.14054083470239093, 0.12278456090290428, 0.10510423526567632, 0.08748866352592408, 0.0699268119435107, 0.05240777928304168, 0.0349207694917484, 0.017455064928217568, 1.83697019872103e-16, -0.0174550649282172, -0.034920769491748035, -0.05240777928304132, -0.06992681194351033, -0.08748866352592372, -0.10510423526567599, -0.1227845609029048, -0.14054083470239143, -0.1583844403245361, -0.17632698070846456, -0.19438030913771787, -0.2125565616700213, -0.23086819112556303, -0.24932800284318035, -0.26794919243112314, -0.28674538575880815, -0.3057306814586604, -0.32491969623290606, -0.34432761328966477, -0.36397023426620173, -0.3838640350354149, -0.40402622583515674, -0.42447481620960437, -0.4452286853085366, -0.46630765815499886, -0.4877325885658614, -0.5095254494944286, -0.5317094316614782, -0.5543090514527681, -0.5773502691896258, -0.6008606190275602, -0.624869351909327, -0.6494075931975098, -0.6745085168424256, -0.7002075382097097, -0.7265425280053606, -0.7535540501027934, -0.7812856265067178, -0.8097840331950074, -0.8390996311772798, -0.8692867378162261, -0.9004040442978388, -0.9325150861376603, -0.9656887748070723, -0.9999999999999998, -1.0355303137905687, -1.0723687100246833, -1.110612514829193, -1.1503684072210092, -1.1917535925942093, -1.2348971565350502, -1.279941632193077, -1.32704482162041, -1.3763819204711731, -1.4281480067421135, -1.4825609685127383, -1.5398649638145834, -1.6003345290410467, -1.6642794823505167, -1.732050807568875, -1.8040477552714247, -1.880726465346332, -1.9626105055051497, -2.050303841579299, -2.144506920509555, -2.246036773904217, -2.3558523658237465, -2.4750868534162938, -2.605089064693797, -2.7474774194546243, -2.904210877675814, -3.0776835371752513, -3.270852618484146, -3.4874144438409007, -3.732050807568878, -4.010780933535842, -4.331475874284148, -4.704630109478442, -5.144554015970314, -5.671281819617678, -6.313751514675033, -7.115369722384186, -8.14434642797455, -9.514364454222589, -11.430052302761325, -14.300666256712038, -19.081136687728016, -28.636253282915728, -57.28996163075635};

#endif