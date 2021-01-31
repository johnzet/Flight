
function [q] = ZQ_defQuat(varargin)
    
rhs = argn(2);
className = 'ZQuat';

select rhs

  case 4
    // ----------------------------------------------
    // 4 arguments : r,i1, i2, i3
    // ----------------------------------------------
    r = varargin(1);
    i1 = varargin(2);
    i2 = varargin(3);
    i3 = varargin(4);

    si1 = size(i1);
    si2 = size(i2);
    si3 = size(i3);
 
    if ( si1(1) <> si2(1) | si1(2) <> si2(2) | ..
         si1(1) <> si3(1) | si1(2) <> si3(2))
       error("Invalid argument sizes"); 
    end

    q = mlist([className, 'r', 'i'], r, [i1;i2;i3]);

  case 2
    r = varargin(1);
    i = varargin(2);

    sr = size(r);
    si = size(i); 

    if ~(sr(1) == 1 & si(1) == 3 & sr(2) == 1 & si(2) == 1)
        error("Invalid arguments sizes"); 
    end

    q = mlist([className,'r','i'], r, i);
  else
    error("Invalid argument length");
    
end
endfunction
