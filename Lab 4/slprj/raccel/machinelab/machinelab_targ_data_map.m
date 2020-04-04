  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% rtP.torque_in
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.u00V_Amplitude
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.u00V_Amplitude_e2esohy1ez
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.DCMachine_Ifinit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.CoulombTfViscousBmwFrictionTorques_gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.CoulombTfViscousBmwFrictionTorques_offset
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Integrator_IC
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.StateSpace_P1_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.StateSpace_P1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.StateSpace_P2_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 30;
	
	  ;% rtP.StateSpace_P2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 32;
	
	  ;% rtP.StateSpace_P3_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 36;
	
	  ;% rtP.StateSpace_P3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 38;
	
	  ;% rtP.StateSpace_P4_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 39;
	
	  ;% rtP.StateSpace_P4
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 41;
	
	  ;% rtP.StateSpace_P1_Size_adoog3rqvr
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 195;
	
	  ;% rtP.StateSpace_P1_dkwwqo4but
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 197;
	
	  ;% rtP.StateSpace_P2_Size_paopbwwf1f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 215;
	
	  ;% rtP.StateSpace_P2_bxxikatvaj
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 217;
	
	  ;% rtP.StateSpace_P3_Size_go4kcbs35n
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 221;
	
	  ;% rtP.StateSpace_P3_jszlhufy1b
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 223;
	
	  ;% rtP.StateSpace_P4_Size_pxbc5xkidw
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 224;
	
	  ;% rtP.StateSpace_P4_gpsr2nnnp1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 226;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 364;
	
	  ;% rtP.donotdeletethisgain_Gain_pkhopsoosh
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 365;
	
	  ;% rtP.E_Torque_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 366;
	
	  ;% rtP.Gain1_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 367;
	
	  ;% rtP.donotdeletethisgain_Gain_cd1x1ng35r
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 368;
	
	  ;% rtP.RPM_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 369;
	
	  ;% rtP.Gain2_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 370;
	
	  ;% rtP.Fieldarmaturemutualinductance_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 371;
	
	  ;% rtP.Gain1_Gain_pgyo0kriob
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 372;
	
	  ;% rtP.donotdeletethisgain_Gain_apk3shealt
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 373;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% rtB.ktalma0oac
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.b30kdd5lyw
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.bs0ibbwun2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.au052vs3tz
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtB.i24zaqcf4y
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtB.axnznxzwpp
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtB.hqeqn5dkli
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtB.oz2lj4bjyl
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtB.lyw0ltjhfd
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% rtB.ernhz1ryas
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% rtB.jwfyf5irzt
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% rtB.gqonqebseb
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtB.hdkxcatxsn
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtB.faqpvtnhw1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtB.fu5d2eko22
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtB.b4jg5qsci2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtB.fq1a4cq0jk
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.cth5x4xh3p
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gncxnacjsz
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.nwzbaefmky
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.cskemfc4uv
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 22;
	
	  ;% rtDW.dkgr2cddwe.AQHandles
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 44;
	
	  ;% rtDW.hhtkb2ohjl.AQHandles
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.kwzynvnzgb
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.pmruhnakvl
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 769218363;
  targMap.checksum1 = 1447883138;
  targMap.checksum2 = 927670333;
  targMap.checksum3 = 3409417459;

