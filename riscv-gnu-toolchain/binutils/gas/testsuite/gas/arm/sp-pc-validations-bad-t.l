[^:]*: Assembler messages:
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[r0\]'
[^:]*:17: *Info: macro .*
[^:]*:27: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[r0,#0\]'
[^:]*:17: *Info: macro .*
[^:]*:28: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[sp\]'
[^:]*:17: *Info: macro .*
[^:]*:29: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[sp,#0\]'
[^:]*:17: *Info: macro .*
[^:]*:30: *Info: macro .*
[^:]*:12: Error: branch must be last instruction in IT block -- `ldreq.w r15,\[r0\]'
[^:]*:21: *Info: macro .*
[^:]*:31: *Info: macro .*
[^:]*:12: Error: branch must be last instruction in IT block -- `ldreq.w r15,\[r0,#0\]'
[^:]*:21: *Info: macro .*
[^:]*:32: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[r0,#-4\]'
[^:]*:17: *Info: macro .*
[^:]*:33: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[r0\],#4'
[^:]*:17: *Info: macro .*
[^:]*:34: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[r0,#0\]!'
[^:]*:17: *Info: macro .*
[^:]*:35: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,label'
[^:]*:17: *Info: macro .*
[^:]*:38: *Info: macro .*
[^:]*:12: Error: branch must be last instruction in IT block -- `ldreq.w r15,label'
[^:]*:21: *Info: macro .*
[^:]*:39: *Info: macro .*
[^:]*:12: Error: branch must be last instruction in IT block -- `ldreq.w r15,\[pc,#-0\]'
[^:]*:21: *Info: macro .*
[^:]*:40: *Info: macro .*
[^:]*:6: Error: branch must be last instruction in IT block -- `ldreq r15,\[r0,r1\]'
[^:]*:17: *Info: macro .*
[^:]*:43: *Info: macro .*
[^:]*:12: Error: branch must be last instruction in IT block -- `ldreq.w r15,\[r0,r1\]'
[^:]*:21: *Info: macro .*
[^:]*:44: *Info: macro .*
[^:]*:12: Error: branch must be last instruction in IT block -- `ldreq.w r15,\[r0,r1,LSL#2\]'
[^:]*:21: *Info: macro .*
[^:]*:45: *Info: macro .*
[^:]*:48: Error: r15 not allowed here -- `ldrb pc,\[r0,#4\]'
[^:]*:50: Error: r13 not allowed here -- `ldrb.w sp,\[r0,#4\]'
[^:]*:51: Error: r15 not allowed here -- `ldrb.w pc,\[r0,#4\]'
[^:]*:52: Error: r15 not allowed here -- `ldrb pc,\[r0,#-4\]'
[^:]*:54: Error: r15 not allowed here -- `ldrb pc,\[r0\],#4'
[^:]*:55: Error: r13 not allowed here -- `ldrb sp,\[r0\],#4'
[^:]*:56: Error: r15 not allowed here -- `ldrb pc,\[r0,#4\]!'
[^:]*:57: Error: r13 not allowed here -- `ldrb sp,\[r0,#4\]!'
[^:]*:60: Error: r15 not allowed here -- `ldrb pc,label'
[^:]*:61: Error: r15 not allowed here -- `ldrb pc,\[PC,#-0\]'
[^:]*:62: Error: r13 not allowed here -- `ldrb sp,label'
[^:]*:63: Error: r13 not allowed here -- `ldrb sp,\[PC,#-0\]'
[^:]*:66: Error: r15 not allowed here -- `ldrb pc,\[r0,r1\]'
[^:]*:67: Error: cannot use register index with PC-relative addressing -- `ldrb r0,\[pc,r1\]'
[^:]*:68: Error: r15 not allowed here -- `ldrb r0,\[r1,pc\]'
[^:]*:69: Error: r15 not allowed here -- `ldrb.w pc,\[r0,r1,LSL#1\]'
[^:]*:70: Error: r13 not allowed here -- `ldrb.w sp,\[r0,r1\]'
[^:]*:71: Error: r15 not allowed here -- `ldrb.w r2,\[r0,pc,LSL#2\]'
[^:]*:72: Error: r13 not allowed here -- `ldrb.w r2,\[r0,sp,LSL#2\]'
[^:]*:75: Error: r15 not allowed here -- `ldrbt pc,\[r0,#4\]'
[^:]*:76: Error: r13 not allowed here -- `ldrbt sp,\[r0,#4\]'
[^:]*:79: Error: r15 not allowed here -- `ldrd pc,r0,\[r1\]'
[^:]*:80: Error: r13 not allowed here -- `ldrd sp,r0,\[r1\]'
[^:]*:81: Error: r12 not allowed here -- `ldrd r12,\[r1\]'
[^:]*:82: Error: r14 not allowed here -- `ldrd r14,\[r1\]'
[^:]*:83: Error: r15 not allowed here -- `ldrd r0,pc,\[r1\]'
[^:]*:84: Error: r13 not allowed here -- `ldrd r0,sp,\[r1\]'
[^:]*:85: Error: r15 not allowed here -- `ldrd pc,r0,\[r1\],#4'
[^:]*:86: Error: r13 not allowed here -- `ldrd sp,r0,\[r1\],#4'
[^:]*:87: Error: r15 not allowed here -- `ldrd r0,pc,\[r1\],#4'
[^:]*:88: Error: r13 not allowed here -- `ldrd r0,sp,\[r1\],#4'
[^:]*:89: Error: r12 not allowed here -- `ldrd r12,\[r1\],#4'
[^:]*:90: Error: r14 not allowed here -- `ldrd r14,\[r1\],#4'
[^:]*:91: Error: r15 not allowed here -- `ldrd pc,r0,\[r1,#4\]!'
[^:]*:92: Error: r13 not allowed here -- `ldrd sp,r0,\[r1,#4\]!'
[^:]*:93: Error: r15 not allowed here -- `ldrd r0,pc,\[r1,#4\]!'
[^:]*:94: Error: r13 not allowed here -- `ldrd r0,sp,\[r1,#4\]!'
[^:]*:95: Error: r12 not allowed here -- `ldrd r12,\[r1,#4\]!'
[^:]*:96: Error: r14 not allowed here -- `ldrd r14,\[r1,#4\]!'
[^:]*:99: Error: r15 not allowed here -- `ldrd pc,r0,label'
[^:]*:100: Error: r13 not allowed here -- `ldrd sp,r0,label'
[^:]*:101: Error: r15 not allowed here -- `ldrd r0,pc,label'
[^:]*:102: Error: r13 not allowed here -- `ldrd r0,sp,label'
[^:]*:103: Error: r15 not allowed here -- `ldrd pc,r0,\[pc,#-0\]'
[^:]*:104: Error: r13 not allowed here -- `ldrd sp,r0,\[pc,#-0\]'
[^:]*:105: Error: r15 not allowed here -- `ldrd r0,pc,\[pc,#-0\]'
[^:]*:106: Error: r13 not allowed here -- `ldrd r0,sp,\[pc,#-0\]'
[^:]*:111: Error: r15 not allowed here -- `ldrex pc,\[r0\]'
[^:]*:112: Error: r13 not allowed here -- `ldrex sp,\[r0\]'
[^:]*:113: Error: r15 not allowed here -- `ldrex r0,\[pc\]'
[^:]*:114: Error: r15 not allowed here -- `ldrexb pc,\[r0\]'
[^:]*:115: Error: r13 not allowed here -- `ldrexb sp,\[r0\]'
[^:]*:116: Error: r15 not allowed here -- `ldrexb r0,\[pc\]'
[^:]*:117: Error: r15 not allowed here -- `ldrexd pc,r0,\[r1\]'
[^:]*:118: Error: r13 not allowed here -- `ldrexd sp,r0,\[r1\]'
[^:]*:119: Error: r15 not allowed here -- `ldrexd r0,pc,\[r1\]'
[^:]*:120: Error: r13 not allowed here -- `ldrexd r0,sp,\[r1\]'
[^:]*:121: Error: r15 not allowed here -- `ldrexd r0,r1,\[pc\]'
[^:]*:122: Error: r15 not allowed here -- `ldrexh pc,\[r0\]'
[^:]*:123: Error: r13 not allowed here -- `ldrexh sp,\[r0\]'
[^:]*:124: Error: r15 not allowed here -- `ldrexh r0,\[pc\]'
[^:]*:127: Error: r15 not allowed here -- `ldrh pc,\[r0\]'
[^:]*:128: Error: r15 not allowed here -- `ldrh pc,\[r0,#4\]'
[^:]*:131: Error: r15 not allowed here -- `ldrh.w pc,\[r0\]'
[^:]*:132: Error: r15 not allowed here -- `ldrh.w pc,\[r0,#4\]'
[^:]*:133: Error: r13 not allowed here -- `ldrh.w sp,\[r0\]'
[^:]*:134: Error: r13 not allowed here -- `ldrh.w sp,\[r0,#4\]'
[^:]*:135: Error: r15 not allowed here -- `ldrh pc,\[r0,#-3\]'
[^:]*:137: Error: r15 not allowed here -- `ldrh pc,\[r0\],#4'
[^:]*:138: Error: r13 not allowed here -- `ldrh sp,\[r0\],#4'
[^:]*:139: Error: r15 not allowed here -- `ldrh pc,\[r0,#4\]!'
[^:]*:140: Error: r13 not allowed here -- `ldrh sp,\[r0,#4\]!'
[^:]*:143: Error: r15 not allowed here -- `ldrh pc,label'
[^:]*:144: Error: r15 not allowed here -- `ldrh pc,\[pc,#-0\]'
[^:]*:145: Error: r13 not allowed here -- `ldrh sp,label'
[^:]*:146: Error: r13 not allowed here -- `ldrh sp,\[pc,#-0\]'
[^:]*:149: Error: r15 not allowed here -- `ldrh pc,\[r0,r1\]'
[^:]*:150: Error: cannot use register index with PC-relative addressing -- `ldrh r0,\[pc,r1\]'
[^:]*:151: Error: r15 not allowed here -- `ldrh r0,\[r1,pc\]'
[^:]*:152: Error: r15 not allowed here -- `ldrh.w pc,\[r0,r1,LSL#1\]'
[^:]*:153: Error: r13 not allowed here -- `ldrh.w sp,\[r0,r1,LSL#1\]'
[^:]*:154: Error: r15 not allowed here -- `ldrh.w r2,\[r0,pc,LSL#1\]'
[^:]*:155: Error: r13 not allowed here -- `ldrh.w r2,\[r0,sp,LSL#1\]'
[^:]*:158: Error: r15 not allowed here -- `ldrht pc,\[r0,#4\]'
[^:]*:159: Error: r13 not allowed here -- `ldrht sp,\[r0,#4\]'
[^:]*:162: Error: r15 not allowed here -- `ldrsb pc,\[r0,#4\]'
[^:]*:164: Error: r13 not allowed here -- `ldrsb sp,\[r0,#4\]'
[^:]*:165: Error: r15 not allowed here -- `ldrsb pc,\[r0,#-4\]'
[^:]*:166: Error: r13 not allowed here -- `ldrsb sp,\[r0,#-4\]'
[^:]*:167: Error: r15 not allowed here -- `ldrsb pc,\[r0\],#4'
[^:]*:168: Error: r13 not allowed here -- `ldrsb sp,\[r0\],#4'
[^:]*:169: Error: r15 not allowed here -- `ldrsb pc,\[r0,#4\]!'
[^:]*:170: Error: r13 not allowed here -- `ldrsb sp,\[r0,#4\]!'
[^:]*:173: Error: r15 not allowed here -- `ldrsb pc,label'
[^:]*:174: Error: r15 not allowed here -- `ldrsb pc,\[pc,#-0\]'
[^:]*:175: Error: r13 not allowed here -- `ldrsb sp,label'
[^:]*:176: Error: r13 not allowed here -- `ldrsb sp,\[pc,#-0\]'
[^:]*:179: Error: r15 not allowed here -- `ldrsb pc,\[r0,r1\]'
[^:]*:180: Error: cannot use register index with PC-relative addressing -- `ldrsb r0,\[pc,r1\]'
[^:]*:181: Error: r15 not allowed here -- `ldrsb r0,\[r1,pc\]'
[^:]*:182: Error: r15 not allowed here -- `ldrsb.w pc,\[r0,r1,LSL#2\]'
[^:]*:184: Error: r13 not allowed here -- `ldrsb.w sp,\[r0,r1,LSL#2\]'
[^:]*:185: Error: r15 not allowed here -- `ldrsb.w r2,\[r0,pc,LSL#2\]'
[^:]*:186: Error: r13 not allowed here -- `ldrsb.w r2,\[r0,sp,LSL#2\]'
[^:]*:190: Error: r15 not allowed here -- `ldrsbt pc,\[r0,#4\]'
[^:]*:191: Error: r13 not allowed here -- `ldrsbt sp,\[r0,#4\]'
[^:]*:195: Error: r15 not allowed here -- `ldrsh pc,\[r0,#4\]'
[^:]*:196: Error: r13 not allowed here -- `ldrsh sp,\[r0,#4\]'
[^:]*:197: Error: r15 not allowed here -- `ldrsh pc,\[r0,#-4\]'
[^:]*:198: Error: r15 not allowed here -- `ldrsh pc,\[r0\],#4'
[^:]*:199: Error: r15 not allowed here -- `ldrsh pc,\[r0,#4\]!'
[^:]*:200: Error: r13 not allowed here -- `ldrsh sp,\[r0,#-4\]'
[^:]*:201: Error: r13 not allowed here -- `ldrsh sp,\[r0\],#4'
[^:]*:202: Error: r13 not allowed here -- `ldrsh sp,\[r0,#4\]!'
[^:]*:205: Error: r15 not allowed here -- `ldrsh pc,label'
[^:]*:206: Error: r13 not allowed here -- `ldrsh sp,label'
[^:]*:207: Error: r13 not allowed here -- `ldrsh sp,\[pc,#-0\]'
[^:]*:210: Error: r15 not allowed here -- `ldrsh pc,\[r0,r1\]'
[^:]*:211: Error: cannot use register index with PC-relative addressing -- `ldrsh r0,\[pc,r1\]'
[^:]*:212: Error: r15 not allowed here -- `ldrsh r0,\[r1,pc\]'
[^:]*:214: Error: r15 not allowed here -- `ldrsh.w pc,\[r0,r1,LSL#3\]'
[^:]*:215: Error: r13 not allowed here -- `ldrsh.w sp,\[r0,r1,LSL#3\]'
[^:]*:216: Error: r13 not allowed here -- `ldrsh.w r0,\[r1,sp,LSL#3\]'
[^:]*:217: Error: r15 not allowed here -- `ldrsh.w r0,\[r1,pc,LSL#3\]'
[^:]*:221: Error: r15 not allowed here -- `ldrsht pc,\[r0,#4\]'
[^:]*:222: Error: r13 not allowed here -- `ldrsht sp,\[r0,#4\]'
[^:]*:226: Error: r15 not allowed here -- `ldrt pc,\[r0,#4\]'
[^:]*:227: Error: r13 not allowed here -- `ldrt sp,\[r0,#4\]'
[^:]*:232: Error: r15 not allowed here -- `str pc,\[r0,#4\]'
[^:]*:233: Error: cannot use register index with PC-relative addressing -- `str.w r0,\[pc,#4\]'
[^:]*:234: Error: cannot use register index with PC-relative addressing -- `str r0,\[pc,#-4\]'
[^:]*:235: Error: cannot use post-indexing with PC-relative addressing -- `str r0,\[pc\],#4'
[^:]*:236: Error: cannot use writeback with PC-relative addressing -- `str r0,\[pc,#4\]!'
[^:]*:239: Error: cannot use register index with PC-relative addressing -- `str.w r0,\[pc,r1\]'
[^:]*:240: Error: cannot use register index with PC-relative addressing -- `str.w r0,\[pc,r1,LSL#2\]'
[^:]*:246: Error: cannot use register index with PC-relative addressing -- `strb.w r0,\[pc,#4\]'
[^:]*:247: Error: r15 not allowed here -- `strb.w pc,\[r0,#4\]'
[^:]*:248: Error: r13 not allowed here -- `strb.w sp,\[r0,#4\]'
[^:]*:249: Error: cannot use register index with PC-relative addressing -- `strb r0,\[pc,#-4\]'
[^:]*:250: Error: cannot use post-indexing with PC-relative addressing -- `strb r0,\[pc\],#4'
[^:]*:251: Error: cannot use writeback with PC-relative addressing -- `strb r0,\[pc,#4\]!'
[^:]*:252: Error: r15 not allowed here -- `strb pc,\[r0,#-4\]'
[^:]*:253: Error: r15 not allowed here -- `strb pc,\[r0\],#4'
[^:]*:254: Error: r15 not allowed here -- `strb pc,\[r0,#4\]!'
[^:]*:255: Error: r13 not allowed here -- `strb sp,\[r0,#-4\]'
[^:]*:256: Error: r13 not allowed here -- `strb sp,\[r0\],#4'
[^:]*:257: Error: r13 not allowed here -- `strb sp,\[r0,#4\]!'
[^:]*:260: Error: cannot use register index with PC-relative addressing -- `strb.w r0,\[pc,r1\]'
[^:]*:261: Error: cannot use register index with PC-relative addressing -- `strb.w r0,\[pc,r1,LSL#2\]'
[^:]*:262: Error: r15 not allowed here -- `strb.w pc,\[r0,r1\]'
[^:]*:263: Error: r15 not allowed here -- `strb.w pc,\[r0,r1,LSL#2\]'
[^:]*:264: Error: r13 not allowed here -- `strb.w sp,\[r0,r1\]'
[^:]*:265: Error: r13 not allowed here -- `strb.w sp,\[r0,r1,LSL#2\]'
[^:]*:266: Error: r15 not allowed here -- `strb.w r0,\[r1,pc\]'
[^:]*:267: Error: r15 not allowed here -- `strb.w r0,\[r1,pc,LSL#2\]'
[^:]*:268: Error: r13 not allowed here -- `strb.w r0,\[r1,sp\]'
[^:]*:269: Error: r13 not allowed here -- `strb.w r0,\[r1,sp,LSL#2\]'
[^:]*:272: Error: cannot use register index with PC-relative addressing -- `strbt r0,\[pc,#4\]'
[^:]*:273: Error: r15 not allowed here -- `strbt pc,\[r0,#4\]'
[^:]*:274: Error: r13 not allowed here -- `strbt sp,\[r0,#4\]'
[^:]*:277: Error: cannot use register index with PC-relative addressing -- `strd r0,r1,\[pc,#4\]'
[^:]*:278: Error: cannot use post-indexing with PC-relative addressing -- `strd r0,r1,\[pc\],#4'
[^:]*:279: Error: cannot use writeback with PC-relative addressing -- `strd r0,r1,\[pc,#4\]!'
[^:]*:280: Error: r15 not allowed here -- `strd pc,r0,\[r1,#4\]'
[^:]*:281: Error: r15 not allowed here -- `strd pc,r0,\[r1\],#4'
[^:]*:282: Error: r15 not allowed here -- `strd pc,r0,\[r1,#4\]!'
[^:]*:283: Error: r13 not allowed here -- `strd sp,r0,\[r1,#4\]'
[^:]*:284: Error: r13 not allowed here -- `strd sp,r0,\[r1\],#4'
[^:]*:285: Error: r13 not allowed here -- `strd sp,r0,\[r1,#4\]!'
[^:]*:286: Error: r15 not allowed here -- `strd r0,pc,\[r1,#4\]'
[^:]*:287: Error: r15 not allowed here -- `strd r0,pc,\[r1\],#4'
[^:]*:288: Error: r15 not allowed here -- `strd r0,pc,\[r1,#4\]!'
[^:]*:289: Error: r13 not allowed here -- `strd r0,sp,\[r1,#4\]'
[^:]*:290: Error: r13 not allowed here -- `strd r0,sp,\[r1\],#4'
[^:]*:291: Error: r13 not allowed here -- `strd r0,sp,\[r1,#4\]!'
[^:]*:297: Error: r15 not allowed here -- `strex pc,r0,\[r1\]'
[^:]*:298: Error: r15 not allowed here -- `strex pc,r0,\[r1,#4\]'
[^:]*:299: Error: r13 not allowed here -- `strex sp,r0,\[r1\]'
[^:]*:300: Error: r13 not allowed here -- `strex sp,r0,\[r1,#4\]'
[^:]*:301: Error: r15 not allowed here -- `strex r0,pc,\[r1\]'
[^:]*:302: Error: r15 not allowed here -- `strex r0,pc,\[r1,#4\]'
[^:]*:303: Error: r13 not allowed here -- `strex r0,sp,\[r1\]'
[^:]*:304: Error: r13 not allowed here -- `strex r0,sp,\[r1,#4\]'
[^:]*:305: Error: r15 not allowed here -- `strex r0,r1,\[pc\]'
[^:]*:306: Error: r15 not allowed here -- `strex r0,r1,\[pc,#4\]'
[^:]*:309: Error: r15 not allowed here -- `strexb pc,r0,\[r1\]'
[^:]*:310: Error: r13 not allowed here -- `strexb sp,r0,\[r1\]'
[^:]*:311: Error: r15 not allowed here -- `strexb r0,pc,\[r1\]'
[^:]*:312: Error: r13 not allowed here -- `strexb r0,sp,\[r1\]'
[^:]*:313: Error: r15 not allowed here -- `strexb r0,r1,\[pc\]'
[^:]*:316: Error: r15 not allowed here -- `strexd pc,r0,r1,\[r2\]'
[^:]*:317: Error: r13 not allowed here -- `strexd sp,r0,r1,\[r2\]'
[^:]*:318: Error: r15 not allowed here -- `strexd r0,pc,r1,\[r2\]'
[^:]*:319: Error: r13 not allowed here -- `strexd r0,sp,r1,\[r2\]'
[^:]*:320: Error: r15 not allowed here -- `strexd r0,r1,pc,\[r2\]'
[^:]*:321: Error: r13 not allowed here -- `strexd r0,r1,sp,\[r2\]'
[^:]*:322: Error: r15 not allowed here -- `strexd r0,r1,r2,\[pc\]'
[^:]*:325: Error: r15 not allowed here -- `strexh pc,r0,\[r1\]'
[^:]*:326: Error: r13 not allowed here -- `strexh sp,r0,\[r1\]'
[^:]*:327: Error: r15 not allowed here -- `strexh r0,pc,\[r1\]'
[^:]*:328: Error: r13 not allowed here -- `strexh r0,sp,\[r1\]'
[^:]*:329: Error: r15 not allowed here -- `strexh r0,r1,\[pc\]'
[^:]*:332: Error: cannot use register index with PC-relative addressing -- `strh.w r0,\[pc\]'
[^:]*:333: Error: cannot use register index with PC-relative addressing -- `strh.w r0,\[pc,#4\]'
[^:]*:334: Error: cannot use register index with PC-relative addressing -- `strh r0,\[pc,#-4\]'
[^:]*:335: Error: cannot use post-indexing with PC-relative addressing -- `strh r0,\[pc\],#4'
[^:]*:336: Error: cannot use writeback with PC-relative addressing -- `strh r0,\[pc,#4\]!'
[^:]*:339: Error: cannot use register index with PC-relative addressing -- `strh.w r0,\[pc,r1\]'
[^:]*:340: Error: cannot use register index with PC-relative addressing -- `strh.w r0,\[pc,r1,LSL#2\]'
[^:]*:341: Error: r15 not allowed here -- `strh.w pc,\[r0,#4\]'
[^:]*:342: Error: r15 not allowed here -- `strh.w pc,\[r0\]'
[^:]*:343: Error: r13 not allowed here -- `strh.w sp,\[r0,#4\]'
[^:]*:344: Error: r13 not allowed here -- `strh.w sp,\[r0\]'
[^:]*:345: Error: r15 not allowed here -- `strh pc,\[r0,#-4\]'
[^:]*:346: Error: r15 not allowed here -- `strh pc,\[r0\],#4'
[^:]*:347: Error: r15 not allowed here -- `strh pc,\[r0,#4\]!'
[^:]*:348: Error: r13 not allowed here -- `strh sp,\[r0,#-4\]'
[^:]*:349: Error: r13 not allowed here -- `strh sp,\[r0\],#4'
[^:]*:350: Error: r13 not allowed here -- `strh sp,\[r0,#4\]!'
[^:]*:351: Error: r15 not allowed here -- `strh.w pc,\[r0,r1\]'
[^:]*:352: Error: r13 not allowed here -- `strh.w sp,\[r0,r1\]'
[^:]*:353: Error: r15 not allowed here -- `strh.w r0,\[r1,pc\]'
[^:]*:354: Error: r13 not allowed here -- `strh.w r0,\[r1,sp\]'
[^:]*:355: Error: r15 not allowed here -- `strh.w pc,\[r0,r1,LSL#2\]'
[^:]*:356: Error: r13 not allowed here -- `strh.w sp,\[r0,r1,LSL#2\]'
[^:]*:357: Error: r15 not allowed here -- `strh.w r0,\[r1,pc,LSL#2\]'
[^:]*:358: Error: r13 not allowed here -- `strh.w r0,\[r1,sp,LSL#2\]'
[^:]*:361: Error: cannot use register index with PC-relative addressing -- `strht r0,\[pc,#4\]'
[^:]*:362: Error: r15 not allowed here -- `strht pc,\[r0,#4\]'
[^:]*:363: Error: r13 not allowed here -- `strht sp,\[pc,#4\]'
[^:]*:366: Error: cannot use register index with PC-relative addressing -- `strt r0,\[pc,#4\]'
[^:]*:367: Error: r15 not allowed here -- `strt pc,\[r0,#4\]'
[^:]*:368: Error: r13 not allowed here -- `strt sp,\[r0,#4\]'