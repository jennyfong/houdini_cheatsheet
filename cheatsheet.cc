Houdini Script

rand(@Frame)
noise(@P.x, @P.y, @P.z)

VEX

point(0, "P", point_number);

int max_search_points = 1;

int handle = pcopen(0, "P", @P, chi("search_radius"), max_search_points);

while(pciterate(handle)){
  int nearpt;
  if(pcimport(handle, "point.number", nearpt)){
    int colliding = point(0, "colliding", nearpt);
    vector rest_nearP = point(2, "P", nearpt);
    vector restP = point(2, "P", @ptnum);
    
    float dist = distance(restP, rest_nearP);
  }
}


--
vector hitP, hituv;

int hitprim  = intersect(1, @P+{0, -5000, 0}, {0, 5000, 0}, hitP, hituv);
if(hitprim != -1){
  f@disp -= @P.y - hitP.y;
  @P.y = hitP.y;
  v@collision_N = primuv(1, "N", hitprim, hituv);
  i@collided = 1;
  i@colliding = 1; 
  f@dist = 0;
}
else{
  i@colliding = 0;
}

vector center = chv("center");
int handle  = pcopen(1, "P", @P, ch("max_distance"), 1);

center =  pcfilter(handle, "P")  ;

//if(pcnumfound(handle)> 0) @Cd = set(1, 0, 0);

vector len = @P - center;

float amp = pow(fit(length(len), 0, ch("max_distance"), 1, 0), ch("exp")) * min(pcnumfound(handle), 1);
@N = normalize(len) * amp;

f@density = amp  ;
 

----
int npts = npoints(0);

for(int pt=0; pt <npts; pt++){
                        
}
                        
foreach(int nearpt; nearpts){
     }                       

# vectors
vector unit_vector_y = set(0, 1, 0);
/* If the vector is pointing downward, make it point stright down */

if(dot(unit_vector_y, normalize(v@v) <= 0){
    v@v = set(0, -1, 0)
}

# volume distance 
float dist = volumesample(1, 'collision', @P);
vector grad = volumegradient(1, 'collision', @P);

  
   
