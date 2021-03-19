class Scene{
	public:

		// camera Object
		Camera cam;
		
		// Models
		std::vector<Group>*groups = new std::vector<Group>() ;
		std::map<std::string,Model*>*modelTable = new std::map<std::string,Model*>();
		
		// - Engine Runtime Options
		// Mode of polygon (fill / line)
		int polyMode = GL_FILL;
		// Origin Axis
		int oAxisDr = 100;
		// cameraCenter Axis
		int ccAxisDr = 0;


		//- Engine Starter Options
		std::vector<float> background{0.2f,0.2f,0.3f,0.2f};


		void drawGroups(){
			for (Group g: (*groups)){
				g.makeGroup();
			}
		}

		void setBackColor(){
			glClearColor(background[0],background[1],background[2],background[3]);
		}


		// Draw the axis centered on Origin
		void axis(){
			glBegin(GL_LINES);
			// X axis in red
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f( oAxisDr, 0.0f, 0.0f);
			// Y Axis in Green
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f,0.0f, 0.0f);
			glVertex3f(0.0f, oAxisDr, 0.0f);
			// Z Axis in Blue
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f,0.0f);
			glVertex3f(0.0f, 0.0f, oAxisDr);
			glEnd();
		}
		

		// Draww the axis centered on CameraCenter
		void ccAxis(){
			glBegin(GL_LINES);
			// X axis in red
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(cam.center[0], cam.center[1], cam.center[2]);
			glVertex3f(cam.center[0]+0.5f, cam.center[1], cam.center[2]);
			// Y Axis in Green
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(cam.center[0], cam.center[1], cam.center[2]);
			glVertex3f(cam.center[0], cam.center[1]+0.5f, cam.center[2]);
			// Z Axis in Blue
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(cam.center[0], cam.center[1], cam.center[2]);
			glVertex3f(cam.center[0], cam.center[1], cam.center[2]+0.5f);
			glEnd();
		}


		// Receive keyboard input and applay options
		void keyboardOpts(unsigned char key, int x, int y){
			switch (key){
				case 'm':
				if (polyMode == GL_FILL) polyMode = GL_LINE;
				else polyMode = GL_FILL;
				break;
		
				case 'o':
				if (oAxisDr == 10) oAxisDr = 0;
				else if (oAxisDr == 100) oAxisDr = 10;
				else oAxisDr = 100;
				break;
		
				case 'i':
				if (ccAxisDr) ccAxisDr = 0;
				else ccAxisDr = 1;
				break;
				
				default:
				break;
			}
		}
};



