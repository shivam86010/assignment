import React from 'react';
import { Card, CardContent, CardMedia, Typography, Button, Avatar, Box } from '@mui/material';
import { Verified } from '@mui/icons-material';

const ProfileCard = () => {
  return (
    <Card sx={{ maxWidth: 345 }}>
      <CardMedia
        component="img"
        height="140"
        image="https://via.placeholder.com/140" // Replace with the actual image URL
        alt="avatar"
      />
      <CardContent>
        <Box display="flex" alignItems="center">
          <Avatar src="https://via.placeholder.com/40" alt="avatar" />
          <Box ml={2}>
            <Typography variant="h6" component="div">
              Roger Korsgaard <Verified color="primary" />
            </Typography>
            <Typography variant="body2" color="text.secondary">
              Daytrader
            </Typography>
          </Box>
        </Box>
        <Typography variant="body2" color="text.secondary" mt={2}>
          20 Alerts
        </Typography>
        <Typography variant="body2" color="text.secondary">
          497 Trades
        </Typography>
        <Typography variant="body2" color="text.secondary">
          90% Avg Gain
        </Typography>
      </CardContent>
      <Button size="small" color="primary">
        Profile
      </Button>
    </Card>
  );
};

export default ProfileCard;
