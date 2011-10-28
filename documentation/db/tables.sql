create table ORI_DEPTH
(
  integrationDate DATE NOT NULL,
  latitude NUMERIC(6,2) NOT NULL,
  longitude NUMERIC(6,2) NOT NULL,
  depth NUMERIC(12,6) NOT NULL,
  PRIMARY KEY(latitude,longitude)
);
