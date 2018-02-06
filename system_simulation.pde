Barnacle barnacle = new Barnacle();
Net net = new Net();
ProximitySensor proxim = new ProximitySensor();

void setup() {
  print("setup");
  size(600, 600);
  frameRate(30);
}

void draw() {
  background(304);
  clear();

  if (proxim.isHumanDetected) {
    barnacle.close();
    net.lightsOn();
    net.expand();
  } else {
    barnacle.open();
    net.lightsOff();
    net.contract();
  } 

  barnacle.render();
  net.render();
}

// mocking input from proximity sensor
void mouseClicked() {
  proxim.isHumanDetected = !proxim.isHumanDetected;
  print(proxim.isHumanDetected);
}

class Barnacle {
  boolean isBarnacleOpen = false;
  float height = 100;
  final float width = 40;
  final float maxHeight = 200;
  final float minHeight = 20;

  void open() {
    print("barnacle open\n");
    isBarnacleOpen = true;
  }

  void close() {
    print("barnacle close\n");
    isBarnacleOpen = false;
  }

  void render() {
    if (barnacle.isBarnacleOpen) {
      print("barnacle open render\n");
      if (height < maxHeight) {
        height++;
      }
    } else {
      print("barnacle close render\n");
      if (height > minHeight) {
        height--;
      } 
    }
    fill(255);
    text("barnacle", 100, 50);
    rect(100, 100, width, height);
  }
}

class Net {
  boolean isLightsOn = false;
  boolean isContracting = false;
  float diameter = 100;
  final float minDiameter = 20;
  final float maxDiameter = 200;

  void lightsOn() {
    isLightsOn = true;
  }
  
  void lightsOff() {
    isLightsOn = false;
  }

  void contract() {
    isContracting = true;
  }

  void expand() {
    isContracting = false;
  }

  void render() {
    if (isContracting) {
      print("net contracting render\n");
      if (diameter > minDiameter) {
        diameter--;
      }  
    } else {
      print("net expanding render\n");
      if (diameter < maxDiameter) {
        diameter++;
      }
    }
    if (isLightsOn) {
      fill(104, 102, 0);
    } else {  
      fill(204, 102, 0);
    }
    text("net", 300, 50);
    ellipse(300, 300, diameter, diameter);
  }
}

class ProximitySensor {
  boolean isHumanDetected = false;

  //boolean isHumanDetected() {
  //  // read the input 
  //  return true;
  //}
}