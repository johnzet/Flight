function VertexData = GeoVerMakeBlock(Location,Orientation)

    r = Location;
    R = Orientation;
    
    // Vertices
    VertexData_0 = ...
        [0.1,0,0;
        -0.05,-0.2,0;
        -0.05,0.2,0;
        
        -0.1,0,0;
        -0.15,-0.07,0;
        -0.15,0.07,0;
        
        -0.1,0,0;
        -0.15,0,0;
        -0.15,0,0.07];
    
    n_ver = 9;
    
    for i_ver=1:n_ver
        
        VertexData(i_ver,:) = r + VertexData_0(i_ver,:)*R';
    end

endfunction

function [PatchData_X,PatchData_Y,PatchData_Z] = GeoPatMakeBlock(VertexData)

    // Patches
    Index_Patch = ...
        [1,2,3;
        4,5,6;
        7,8,9];
    
    n_pat = 3;
    
    for i_pat=1:n_pat
        
        PatchData_X(:,i_pat) = VertexData(Index_Patch(i_pat,:),1);
        PatchData_Y(:,i_pat) = VertexData(Index_Patch(i_pat,:),2);
        PatchData_Z(:,i_pat) = VertexData(Index_Patch(i_pat,:),3);
    end

endfunction
